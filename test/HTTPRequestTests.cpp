/******************************************************************
 *
 * uHTTP for C++
 *
 * Copyright (C) Satoshi Konno 2002
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>
#include <boost/test/unit_test.hpp>

#include <uhttp/HTTP.h>

using namespace std;
using namespace uHTTP;

BOOST_AUTO_TEST_CASE(HTTPReqContentRangeTests)
{
  HTTPRequest httpReq;

  // The first 500 bytes:
  httpReq.setContentRange(0, 499, 1234);
  BOOST_CHECK(httpReq.getContentRangeFirstPosition() == 0);
  BOOST_CHECK(httpReq.getContentRangeLastPosition() == 499);
  BOOST_CHECK(httpReq.getContentRangeInstanceLength() == 1234);

  // The second 500 bytes:
  httpReq.setContentRange(500, 999, 1234);
  BOOST_CHECK(httpReq.getContentRangeFirstPosition() == 500);
  BOOST_CHECK(httpReq.getContentRangeLastPosition() == 999);
  BOOST_CHECK(httpReq.getContentRangeInstanceLength() == 1234);

  // All except for the first 500 bytes:
  httpReq.setContentRange(500, 1233, 1234);
  BOOST_CHECK(httpReq.getContentRangeFirstPosition() == 500);
  BOOST_CHECK(httpReq.getContentRangeLastPosition() == 1233);
  BOOST_CHECK(httpReq.getContentRangeInstanceLength() == 1234);

  // All except for the first 500 bytes:
  httpReq.setContentRange(734, 1233, 1234);
  BOOST_CHECK(httpReq.getContentRangeFirstPosition() == 734);
  BOOST_CHECK(httpReq.getContentRangeLastPosition() == 1233);
  BOOST_CHECK(httpReq.getContentRangeInstanceLength() == 1234);

  // All except for the first 500 bytes:
  httpReq.setContentRange(734, 1233, 0);
  BOOST_CHECK(httpReq.getContentRangeFirstPosition() == 734);
  BOOST_CHECK(httpReq.getContentRangeLastPosition() == 1233);
  BOOST_CHECK(httpReq.getContentRangeInstanceLength() == 0);
}

BOOST_AUTO_TEST_CASE(HTTPReqConnectionTests)
{
  HTTPRequest httpReq;

  httpReq.setConnection(HTTP::CLOSE);
  BOOST_CHECK(httpReq.isCloseConnection() == true);

  httpReq.setConnection(HTTP::KEEP_ALIVE);
  BOOST_CHECK(httpReq.isKeepAliveConnection() == true);
}
