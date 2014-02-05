/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/


#ifndef _CNET_DATAGRAMPACKET_H_
#define _CNET_DATAGRAMPACKET_H_

#include <uhttp/net/InetSocketAddress.h>

#include <string>

namespace uHTTP {
class DatagramPacket {
  InetSocketAddress sockAddr;
  std::string data;

 public:
  DatagramPacket() {
  }

  DatagramPacket(const std::string &msg, InetSocketAddress *addr) {
    setData(msg);
    setSocketAddress(addr);
  }

  ~DatagramPacket() {
  }

  ////////////////////////////////////////////////
  //  date
  ////////////////////////////////////////////////

  void setData(const std::string &value) {
    data = value;
  }

  const char *getData() {
    return data.c_str();
  }

  int getLength() {
    return (int)data.length();
  }

  ////////////////////////////////////////////////
  //  address/port
  ////////////////////////////////////////////////

  void setSocketAddress(InetSocketAddress *addr) {
    sockAddr.set(addr);
  }

  InetSocketAddress *getSocketAddress() {
    return &sockAddr;
  }

  void setAddress(const std::string &addr) {
    sockAddr.setAddress(addr);
  }

  void setPort(int port) {
    sockAddr.setPort(port);
  }

  const char *getAddress() {
    return sockAddr.getAddress();
  }

  int getPort() {
    return sockAddr.getPort();
  }

  void set(DatagramPacket *dgmPack) {
    if (dgmPack == NULL) {
      setSocketAddress(NULL);
      setData("");
      return;
    }
    setSocketAddress(dgmPack->getSocketAddress());
    setData(dgmPack->getData());
  }
};

}

#endif
