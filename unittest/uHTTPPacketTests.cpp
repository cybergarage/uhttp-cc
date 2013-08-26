/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <boost/test/unit_test.hpp>
#include <uhttp/HTTP.h>

using namespace uHTTP;

BOOST_AUTO_TEST_CASE(HTTPPacketTests)
{
    const char *TEST_HTTP_HEADER_NAME = "testHeader";
    const char *TEST_HTTP_HEADER2_NAME = "testHeader2";
    const int TEST_HTTP_HEADER_INT_VALUE = 123456;
    const long TEST_HTTP_HEADER_LONG_VALUE = 123456789;
    const char *TEST_HTTP_HEADER_STRING = "testHeader: 123456\r\ntestHeader2: 123456789\r\n" ;
    
    const char TEST_HTTP_CONTENT_RANGE_STRING1[] = "bytes 111-222/333";
    const char TEST_HTTP_CONTENT_RANGE_STRING2[] = "bytes 111-222/*";
    
    const char TEST_HTTP_CASHCTRL_STRING[] = "max-age=123456";

	HTTPPacket *httpPacket;
	HTTPHeader *header;
    std::string headerStr;
    
	// HTTPPacket::setHeader (int)
	httpPacket = new HTTPPacket();
	httpPacket->setHeader(TEST_HTTP_HEADER_NAME, TEST_HTTP_HEADER_INT_VALUE);
	BOOST_CHECK(httpPacket->getHeader(TEST_HTTP_HEADER_NAME) != NULL);
	BOOST_CHECK(httpPacket->getIntegerHeaderValue(TEST_HTTP_HEADER_NAME) ==  TEST_HTTP_HEADER_INT_VALUE);
	delete httpPacket;
    
	// HTTPPacket::setHeader (long)
	httpPacket = new HTTPPacket();
	httpPacket->setHeader(TEST_HTTP_HEADER_NAME, TEST_HTTP_HEADER_LONG_VALUE);
	BOOST_CHECK(httpPacket->getHeader(TEST_HTTP_HEADER_NAME) != NULL);
	BOOST_CHECK(httpPacket->getLongHeaderValue(TEST_HTTP_HEADER_NAME) ==  TEST_HTTP_HEADER_LONG_VALUE);
	delete httpPacket;
    
	// HTTPPacket::getHeaderString
	httpPacket = new HTTPPacket();
	httpPacket->setHeader(TEST_HTTP_HEADER_NAME, TEST_HTTP_HEADER_INT_VALUE);
	httpPacket->setHeader(TEST_HTTP_HEADER2_NAME, TEST_HTTP_HEADER_LONG_VALUE);
	httpPacket->getHeaderString(headerStr);
	BOOST_CHECK(headerStr.compare(TEST_HTTP_HEADER_STRING) == 0);
	delete httpPacket;
    
	// HTTPPacket::setContentRange
	long contentRagne[3];
	httpPacket = new HTTPPacket();
	
	httpPacket->setContentRange(111, 222, 333);
	header = httpPacket->getHeader(HTTP::CONTENT_RANGE);
	BOOST_CHECK(header != NULL);
	BOOST_CHECK(strcmp(header->getValue(), TEST_HTTP_CONTENT_RANGE_STRING1) == 0);
	httpPacket->getContentRange(contentRagne);
	BOOST_CHECK(contentRagne[0] == 111);
	BOOST_CHECK(contentRagne[1] == 222);
	BOOST_CHECK(contentRagne[2] == 333);
	
	httpPacket->setContentRange(111, 222, 0);
	header = httpPacket->getHeader(HTTP::CONTENT_RANGE);
	BOOST_CHECK(header != NULL);
	BOOST_CHECK(strcmp(header->getValue(), TEST_HTTP_CONTENT_RANGE_STRING2) == 0);
	httpPacket->getContentRange(contentRagne);
	BOOST_CHECK(contentRagne[0] == 111);
	BOOST_CHECK(contentRagne[1] == 222);
	BOOST_CHECK(contentRagne[2] == 0);
	delete httpPacket;
	
	// HTTPPacket::setCacheControl
	httpPacket = new HTTPPacket();
	httpPacket->setCacheControl(HTTP::MAX_AGE, 123456);
	header = httpPacket->getHeader(HTTP::CACHE_CONTROL);
	BOOST_CHECK(header != NULL);
	BOOST_CHECK(strcmp(header->getValue(), TEST_HTTP_CASHCTRL_STRING) == 0);
	BOOST_CHECK(strcmp(httpPacket->getCacheControl(), TEST_HTTP_CASHCTRL_STRING) == 0);
	delete httpPacket;
}
