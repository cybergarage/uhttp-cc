/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifdef HAVE_CONFIG_H
#  include "config.h"
#elif defined(__APPLE__)
#define HAVE_IFADDRS_H
#define HAVE_SYS_RESOURCE_H
#endif

#include <string>
#include <vector>

#if defined(HAVE_IFADDRS_H)
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#endif

#if defined(HAVE_SYS_RESOURCE_H)
#include <sys/resource.h>
#endif

#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string.hpp>

#include <uhttp/HTTP.h>
#include <uhttp/net/SocketUtil.h>

using namespace std;
using namespace uHTTP;

void SocketConnectionHttpServerTest(void);

BOOST_AUTO_TEST_CASE(SocketAddrInfoTests)
{
#if defined(HAVE_IFADDRS_H)
  struct addrinfo *addrInfo;
  bool ret = toSocketAddrInfo(SOCK_STREAM, "192.168.100.10", 80, &addrInfo, true);
  if (ret == true)
    freeaddrinfo(addrInfo);
  BOOST_CHECK(ret);
#endif
}

void SocketConnectionHttpServerTest(void)
{
  const char *CG_HOST_IPADDR = "www.cybergarage.org";
  const char *TEST_HTTP_METHOD = "GET /index.html HTTP/1.0";

  Socket *sock;
  ssize_t sentLen;
  ssize_t readLen;
  const char *line;
    
  sock = new Socket();
  BOOST_CHECK(sock != NULL);
  BOOST_CHECK(sock->connect(CG_HOST_IPADDR, 80));
    
  sentLen = sock->send(TEST_HTTP_METHOD, strlen(TEST_HTTP_METHOD));
  BOOST_CHECK(sentLen == strlen(TEST_HTTP_METHOD));
  sentLen = sock->send(HTTP::CRLF, strlen(HTTP::CRLF));
  BOOST_CHECK(sentLen == strlen(HTTP::CRLF));
  sentLen = sock->send(HTTP::CRLF, strlen(HTTP::CRLF));
  BOOST_CHECK(sentLen == strlen(HTTP::CRLF));
    
  SocketInputStream sockIn(sock);
  InputStreamReader inReader(&sockIn);
  BufferedReader bufReader(&inReader);
    
  do {
    line = bufReader.readLine();
    readLen = strlen(line);
    //printf("%d:%s\n", readLen, line);
  } while (2 < readLen);
    
  BOOST_CHECK(sock->close());
  delete sock;
}

BOOST_AUTO_TEST_CASE(SocketHttpTests)
{
  SocketConnectionHttpServerTest();
}

BOOST_AUTO_TEST_CASE(SocketHttpRepeatTests)
{
  size_t socketRepeatCnt = 100;
#if defined(HAVE_SYS_RESOURCE_H)
  struct rlimit resLimit;
  BOOST_CHECK_EQUAL(getrlimit(RLIMIT_NOFILE, &resLimit), 0);
  socketRepeatCnt = resLimit.rlim_cur / 2;
#endif

  size_t startSocketCount = Socket::GetInstanceCount();
  for (size_t n=0; n<socketRepeatCnt; n++) {
    SocketConnectionHttpServerTest();
  }
  size_t endSocketCount = Socket::GetInstanceCount();
  BOOST_CHECK_EQUAL(startSocketCount, endSocketCount);
}

