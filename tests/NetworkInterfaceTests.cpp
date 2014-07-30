/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <string>
#include <vector>

#include <boost/test/unit_test.hpp>

#include <uhttp/HTTP.h>

using namespace std;
using namespace uHTTP;

BOOST_AUTO_TEST_CASE(NetworkInterfaceTests)
{
  NetworkInterfaceList ifList;
  GetHostAddresses(ifList);
  
  size_t ifCnt = ifList.size();
  BOOST_CHECK(0 < ifCnt);
    
}

BOOST_AUTO_TEST_CASE(SocketIPV6Tests)
{
    /*
  NetworkInterfaceList ifList;
  GetHostAddresses(ifList);
  
  int ifCnt = ifList.size();
  BOOST_CHECK(0 < ifCnt);
    
  string ipv6if;
  for (int n=0; n<ifCnt; n++) {
    NetworkInterface *netif = ifList.getNetworkInterface(n);
    const char *ifaddr = netif->getAddress();
    if (IsIPv6Address(ifaddr) == false)
      continue;
    ipv6if = ifaddr;
  }
    
  BOOST_CHECK(0 < ipv6if.size());
     */
}

