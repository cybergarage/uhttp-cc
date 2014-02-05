/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <errno.h>
#include <uhttp/net/SocketImp.h>
#include <uhttp/net/SocketUtil.h>
#include <uhttp/net/HostInterface.h>
#include <uhttp/util/Mutex.h>
#include <uhttp/util/StringUtil.h>

#if !defined(WIN32) && !defined(__CYGWIN__)
#if !defined(BTRON) && !defined(ITRON) && !defined(TENGINE)
#include <fcntl.h>
#include <signal.h>
#endif
#endif

using namespace uHTTP;
using namespace uHTTP;

////////////////////////////////////////////////
//  Constants
////////////////////////////////////////////////

const int SocketImp::STREAM = 1;
const int SocketImp::DGRAM = 2;

////////////////////////////////////////////////
//  SocketInit/Close
////////////////////////////////////////////////

static size_t socketCnt = 0;
static Mutex sockMutex;

#if defined(TENGINE) && defined(TENGINE_NET_KASAGO)
ttUserInterface kaInterfaceHandle;
#endif

void uHTTP::SocketStartup() {
  sockMutex.lock();
  if (socketCnt == 0) {
#if (defined(WIN32) || defined(__CYGWIN__)) && !defined(ITRON)
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
#elif defined(ITRON) && defined(NORTiAPI)
    tcp_ini();
#elif defined(TENGINE) && defined(TENGINE_NET_KASAGO)
    kaInterfaceHandle = ka_tfAddInterface(HostInterface::DEFAULT_IFNAME);
#endif

#if !defined(WIN32) || defined(__CYGWIN__)
#if !defined(BTRON) && !defined(ITRON) && !defined(TENGINE) 
    // Thanks for Brent Hills (10/26/04)
    signal(SIGPIPE,SIG_IGN);
#endif
#endif
  }
  socketCnt++;
  sockMutex.unlock();
}

void uHTTP::SocketCleanup() {
  sockMutex.lock();
  socketCnt--;
  if (socketCnt <= 0) {
#if defined(WIN32) || defined(__CYGWIN__)
    //  WSACleanup( );
#endif
#if !defined(WIN32) || defined(__CYGWIN__)
#if !defined(BTRON) && !defined(ITRON) && !defined(TENGINE) 
    // Thanks for Brent Hills (10/26/04)
    signal(SIGPIPE,SIG_DFL);
#endif
#endif
  }
  sockMutex.unlock();
}

size_t uHTTP::SocketImp::GetInstanceCount() {
  return socketCnt;
}

////////////////////////////////////////////////
//  Constructor/Destructor
////////////////////////////////////////////////

SocketImp::SocketImp() {
  SocketStartup();
  setType(0);
  setLocalAddress("");
  setLocalPort(0);
  setErrorCode(0);
#if (defined(WIN32) && !defined(__CYGWIN__) && !defined(__MINGW32__)) && !defined(ITRON)
  setSocket(INVALID_SOCKET);
#else
  setSocket(-1);
#endif
}

SocketImp::~SocketImp() {
  SocketCleanup();
}

bool SocketImp::isBound() {
#if (defined(WIN32) && !defined(__CYGWIN__) && !defined(__MINGW32__)) && !defined(ITRON)
  return (sock != INVALID_SOCKET) ? true : false;
#else
  return (0 <= sock) ? true : false;
#endif
}

////////////////////////////////////////////////
//  close
////////////////////////////////////////////////

bool SocketImp::close() {
  if (!isBound())
    return true;

#if (defined(WIN32) || defined(__CYGWIN__)) && !defined(ITRON)
  WSAAsyncSelect(sock, NULL, 0, FD_CLOSE);
  shutdown(sock, SD_BOTH );
  closesocket(sock);
  #if !defined(__CYGWIN__) && !defined(__MINGW32__)
  setSocket(INVALID_SOCKET);
  #else
  setSocket(-1);
  #endif
#else
  #if defined(BTRON) || (defined(TENGINE) && !defined(TENGINE_NET_KASAGO))
  so_shutdown(sock, 2);
  so_close(sock);
  #elif defined(TENGINE) && defined(TENGINE_NET_KASAGO)
  ka_tfClose(sock);
  #elif defined(ITRON)
  if (getType() == STREAM) {
    tcp_can_cep(sock, TFN_TCP_ALL);
    tcp_sht_cep(sock);
    tcp_del_cep(sock);
    tcp_cls_cep(sock, TMO_FEVR);
    tcp_del_rep(sock);
  }
  else {
    udp_can_cep(sock, TFN_UDP_ALL);
    udp_del_cep(sock);
  }
  #else
  int flag = fcntl(sock, F_GETFL, 0);
  if (0 <= flag)
    fcntl(sock, F_SETFL, flag | O_NONBLOCK);
  shutdown(sock, 2);
  if (::close(sock) == -1) {
    setErrorCode(errno);
    return false;
  }
  #endif
  setSocket(-1);
#endif

  return true;
}

////////////////////////////////////////////////
//  Socket Option
////////////////////////////////////////////////

bool SocketImp::setReuseAddress(bool flag) {
  int sockOptRet;
#if defined(BTRON) || (defined(TENGINE) && !defined(TENGINE_NET_KASAGO))
  B optval = (flag == true) ? 1 : 0;
  sockOptRet = so_setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (B *)&optval, sizeof(optval));
#elif defined(TENGINE) && defined(TENGINE_NET_KASAGO)
  int optval = (flag == true) ? 1 : 0;
  sockOptRet = ka_setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (const std::string &)&optval, sizeof(optval));
  //printf("setReuseAddress : %d\n", sockOptRet);
#elif defined (ITRON)
  /**** Not Implemented for NORTi ***/
  sockOptRet = -1;
#elif defined (WIN32)
  BOOL optval = (flag == true) ? 1 : 0;
  sockOptRet = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (const char *)&optval, sizeof(optval));
#else
  int optval = (flag == true) ? 1 : 0;
  sockOptRet = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (const char *)&optval, sizeof(optval));
  #ifdef USE_SO_REUSEPORT
  setsockopt(sock, SOL_SOCKET, SO_REUSEPORT, (const std::string &)&optval, sizeof(optval));
  #endif
#endif
  return (sockOptRet == 0) ? true : false;
}

void SocketImp::setTimeout(int timeout) {
#if !defined(BTRON) && !defined(ITRON) && !defined(TENGINE)
  setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char *)&timeout, sizeof(timeout));
  setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char *)&timeout, sizeof(timeout));
#endif
}

////////////////////////////////////////////////
//  setMulticastInterface
////////////////////////////////////////////////

#if defined(TENGINE) && defined(TENGINE_NET_KASAGO)

bool SocketImp::setMulticastInterface(const std::string &ifaddr) {
  NetworkInterfaceList netIfList;

  if (ifaddr == NULL || strlen(ifaddr) <= 0) {
    int netIfCnt = GetHostAddresses(netIfList);
    if (netIfCnt <= 0)
      return false;
    NetworkInterface *netIf = netIfList.getNetworkInterface(0);
    ifaddr = netIf->getAddress();
  }

  struct sockaddr_in sockaddr;
  bool sockAddrSuccess = toSocketAddrIn(ifaddr, 0, &sockaddr, TRUE);
  if (sockAddrSuccess == false)
    return false;

  int optSuccess = ka_setsockopt(sock, IP_PROTOIP, IPO_MULTICAST_IF, (const std::string &)&sockaddr.sin_addr, sizeof(sockaddr.sin_addr));
  if (optSuccess != 0)
    return false;

  return true;
}

#endif
