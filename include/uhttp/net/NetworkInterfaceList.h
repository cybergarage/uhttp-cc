/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _CNET_NETWORKINTERFACELIST_H_
#define _CNET_NETWORKINTERFACELIST_H_

#include <iostream>
#include <uhttp/util/Vector.h>
#include <uhttp/net/NetworkInterface.h>

namespace uHTTP {
class NetworkInterfaceList : public uHTTP::Vector<NetworkInterface>  {
  ////////////////////////////////////////////////
  //  Constructor
  ////////////////////////////////////////////////
  
 public:
  NetworkInterfaceList() 
  {
  }

  ////////////////////////////////////////////////
  //  Methods
  ////////////////////////////////////////////////
  
 public:
  NetworkInterface *getNetworkInterface(size_t n) {
    return get(n);
  }

  void remove(NetworkInterface *netif) {
    if (netif == NULL)
        return;
    delete netif;
    Vector::remove(netif);
  }

  void print() {
    size_t ifNum = size();
    for (size_t n = 0; n < ifNum; n++) {
      NetworkInterface *netif = getNetworkInterface(n);
      const char *addr = netif->getAddress();
      const char *name = netif->getName();
      int idx = netif->getIndex();
      std::cout << "[" << n << "]" <<  addr << ", " << name << ", " << idx << std::endl;
    }
  }
};

}

#endif
