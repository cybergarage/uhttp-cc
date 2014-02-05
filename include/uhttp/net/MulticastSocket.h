/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/


#ifndef _CNET_MULTICASTSOCKET_H_
#define _CNET_MULTICASTSOCKET_H_

#include <uhttp/net/DatagramSocket.h>
#include <uhttp/net/InetSocketAddress.h>
#include <uhttp/net/NetworkInterface.h>

namespace uHTTP {
class MulticastSocket : public DatagramSocket {
 public:
  MulticastSocket();
  MulticastSocket(int port, const std::string &bindAddr);
  ~MulticastSocket();

  bool bind(int port, const std::string &addr);
  
  bool joinGroup(const std::string &mcastAddr, const std::string &ifAddr = NULL);
  bool joinGroup(InetSocketAddress *mcastAddr, NetworkInterface *ifAddr) {
    return joinGroup(mcastAddr->getAddress(), ifAddr->getAddress());
  }

  void setTimeToLive(int ttl);
};

}

#endif
