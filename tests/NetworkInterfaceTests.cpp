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
