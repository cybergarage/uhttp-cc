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

#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string.hpp>

#include <uhttp/HTTP.h>

using namespace uHTTP;

BOOST_AUTO_TEST_CASE(HTTPUri)
{
  URL url;
  
  url.setString("http://www.yahoo.co.jp/index.html");
  BOOST_CHECK_EQUAL(url.getProtocol(), "http");
  BOOST_CHECK_EQUAL(url.getHost(), "www.yahoo.co.jp");
  BOOST_CHECK_EQUAL(url.getPort(), 80);
  BOOST_CHECK_EQUAL(url.getPath(), "/index.html");

  url.setString("https://www.yahoo.co.jp/index.html");
  BOOST_CHECK_EQUAL(url.getProtocol(), "https");
  BOOST_CHECK_EQUAL(url.getHost(), "www.yahoo.co.jp");
  BOOST_CHECK_EQUAL(url.getPort(), 443);
  BOOST_CHECK_EQUAL(url.getPath(), "/index.html");
}

BOOST_AUTO_TEST_CASE(HTTPGetAbsoluteURL)
{
  // URLGetAbsoluteURL
  std::string urlBuf;
  URLGetAbsoluteURL("http://www.cybergarage.org:8080/test.html", "blog/index.html", urlBuf);
  BOOST_CHECK(strcmp(urlBuf.c_str(), "http://www.cybergarage.org:8080/blog/index.html") == 0);
}

BOOST_AUTO_TEST_CASE(HTTPGetHostURL)
{
  // URLGetAbsoluteURL
  std::string urlBuf;
  URLGetAbsoluteURL("http://www.cybergarage.org:8080/test.html", "blog/index.html", urlBuf);
  BOOST_CHECK(strcmp(urlBuf.c_str(), "http://www.cybergarage.org:8080/blog/index.html") == 0);
}
