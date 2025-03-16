/******************************************************************
 *
 * uHTTP for C++
 *
 * Copyright (C) Satoshi Konno 2002
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#include <map>

#include <boost/test/unit_test.hpp>
#include <uhttp/HTTP.h>

using namespace uHTTP;

BOOST_AUTO_TEST_CASE(HTTPStatusString)
{
  std::map<int, std::string> httpStatusMap;

  httpStatusMap[HTTP::CONTINUE] = HTTP::CONTINUE_STRING;
  httpStatusMap[HTTP::PROCESSING] = HTTP::PROCESSING_STRING;

  httpStatusMap[HTTP::OK_REQUEST] = HTTP::OK_REQUEST_STRING;
  httpStatusMap[HTTP::ACCEPTED] = HTTP::ACCEPTED_STRING;
  httpStatusMap[HTTP::NO_CONTENT] = HTTP::NO_CONTENT_STRING;
  httpStatusMap[HTTP::PARTIAL_CONTENT] = HTTP::PARTIAL_CONTENT_STRING;

  httpStatusMap[HTTP::MOVED_PERMANENTLY] = HTTP::MOVED_PERMANENTLY_STRING;
  httpStatusMap[HTTP::FOUND] = HTTP::FOUND_STRING;

  httpStatusMap[HTTP::BAD_REQUEST] = HTTP::BAD_REQUEST_STRING;
  httpStatusMap[HTTP::PRECONDITION_FAILED] = HTTP::PRECONDITION_FAILED_STING;
  httpStatusMap[HTTP::INVALID_RANGE] = HTTP::INVALID_RANGE_STING;
  httpStatusMap[HTTP::INTERNAL_SERVER_ERROR] = HTTP::INTERNAL_SERVER_ERROR_STRING;
  httpStatusMap[HTTP::INTERNAL_CLIENT_ERROR] = HTTP::INTERNAL_CLIENT_ERROR_STRING;
  httpStatusMap[HTTP::OK_REQUEST] = HTTP::OK_REQUEST_STRING;

  for (std::map<int, std::string>::iterator status = httpStatusMap.begin(); status != httpStatusMap.end(); status++) {
    const std::string statusString = HTTP::StatusCodeToString(status->first);
    BOOST_CHECK_EQUAL(statusString.compare(status->second), 0);
  }
}
