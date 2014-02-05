/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/


#ifndef _CNET_DATAGRAMSOCKET_H_
#define _CNET_DATAGRAMSOCKET_H_

#include <uhttp/net/SocketImp.h>
#include <uhttp/net/DatagramPacket.h>

namespace uHTTP {
class DatagramSocket : public SocketImp {
 public:
  DatagramSocket();
  DatagramSocket(int port, const std::string &bindAddr, bool bindAddrFlag = true, bool reuseAddrFlag = false);
  ~DatagramSocket();

  bool bind(int port, const std::string &addr, bool bindAddrFlag = true, bool reuseAddrFlag = false);

  ssize_t send(const std::string &addr, int port, const std::string &data, size_t dataLen = 0);

  ssize_t send(DatagramPacket *dataPack);

  ssize_t receive(DatagramPacket &dataPack);

};

}

#endif
