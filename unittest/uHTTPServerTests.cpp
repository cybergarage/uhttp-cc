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
#include <sstream>


#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string.hpp>

#include <uhttp/HTTP.h>

using namespace std;
using namespace uHTTP;

//////////////////////////////////////////////////////////////////////
// Range Test
//////////////////////////////////////////////////////////////////////

/*
void UPnPTestCase::doContentRangeTest(HTTPRequest *httpReq, const char *host, int port, const char *postUri, bool keepAlive, const char *content, int firstPos, int lastPos)
{
	// CONTENT_RANGE Test	
	httpReq->setMethod(HTTP::GET);
	httpReq->setURI(postUri);
	httpReq->setContentRange(firstPos, lastPos, strlen(content));
	HTTPResponse *httpRes = httpReq->post(host, port, keepAlive);
	BOOST_CHECK(httpRes->isSuccessful() == true);
	string resContent = httpRes->getContent();
	long resContentLen = httpRes->getContentLength();
	long contentLen = lastPos - firstPos + 1;
	string contentStr = content;
	string rangeContent = contentStr.substr(firstPos, (int)contentLen);
	BOOST_CHECK(resContent.compare(rangeContent) == 0);
	BOOST_CHECK(resContentLen == contentLen);
}

void UPnPTestCase::doHTTPServerTest(const char *postUri, bool keepAlive)
{
	NetworkInterfaceList netfiList;
	static int port = 0;
	string content = "123456789abcedfghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int contentLen;
	String rangeContent;
	
	// Change port number to execute this test continuous.
	if (port == 0)
		port = (int)(Random() * 10000.0f) + 30000;
	port++;
	
	// Get First Interface
	BOOST_CHECK(0 < GetHostAddresses(netfiList));
	NetworkInterface *netIf = netfiList.getNetworkInterface(0);
	const char *host = netIf->getAddress();
	
	// Start HTTP Server	
	TestHTTPServer httpServer;
	httpServer.setContent(content.c_str());
	BOOST_CHECK(httpServer.open(host, port) == true);
	BOOST_CHECK(httpServer.start() == true);
    
	// GET Test	
	HTTPResponse *httpRes;
	string resContent;
	long resContentLen;
	HTTPRequest httpReq;
	httpReq.setMethod(HTTP::GET);
	httpReq.setURI(postUri);
	httpRes = httpReq.post(host, port, keepAlive);
	BOOST_CHECK(httpRes->isSuccessful() == true);
	resContent = httpRes->getContent();
	resContentLen = httpRes->getContentLength();
	BOOST_CHECK(content.compare(resContent) == 0);
	BOOST_CHECK(resContentLen == content.length());
    
	// HEAD Test	
	httpReq.setMethod(HTTP::HEAD);
	httpReq.setURI(postUri);
	httpRes = httpReq.post(host, port, keepAlive);
	BOOST_CHECK(httpRes->isSuccessful() == true);
	resContent = httpRes->getContent();
	resContentLen = httpRes->getContentLength();
	contentLen = content.length();
	BOOST_CHECK(resContent.length() == 0);
	BOOST_CHECK(resContentLen == content.length());
	
	// CONTENT_RANGE Test	
	doContentRangeTest(&httpReq, host, port, postUri, keepAlive, content.c_str(), 0, 19);
	doContentRangeTest(&httpReq, host, port, postUri, keepAlive, content.c_str(), 10, 26);
	
	// Stop HTTP Server
	BOOST_CHECK(httpServer.stop() == true);
	BOOST_CHECK(httpServer.close() == true);
}

void UPnPTestCase::testHTTPServer()
{
	// None keep alive test
	doHTTPServerTest(TestHTTPServer::TEST_URI, false);
	doHTTPServerTest(TestHTTPServer::TEST_INPUTSTREAM_URI,false);
	doHTTPServerTest(TestHTTPServer::TEST_CHUNKED_URI,false);
	
	// Keep alive test
	doHTTPServerTest(TestHTTPServer::TEST_URI, true);
	doHTTPServerTest(TestHTTPServer::TEST_INPUTSTREAM_URI,true);
	doHTTPServerTest(TestHTTPServer::TEST_CHUNKED_URI, true);
}
*/

BOOST_AUTO_TEST_CASE(HTTPCotentRangeTest)
{
}

//////////////////////////////////////////////////////////////////////
// Simple Server
//////////////////////////////////////////////////////////////////////

#define UHTTP_HTTP_SERVER_TEST_PORT 8080
#define UHTTP_HTTP_SERVER_TEST_LOOP_COUNT 100
#define UHTTP_HTTP_SERVER_TEST_CONTENT "123456789abcedfghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"


class HTTPSimpleRequestListener : public HTTPRequestListener
{
    void httpRequestRecieved(HTTPRequest *httpReq);
};

BOOST_AUTO_TEST_CASE(HTTPSimpleServer)
{
    HTTPServer httpServer;
    HTTPSimpleRequestListener httpSimpleReqListener;
    httpServer.addRequestListener(&httpSimpleReqListener);
    
    BOOST_CHECK(httpServer.open(UHTTP_HTTP_SERVER_TEST_PORT));
    BOOST_CHECK(httpServer.start());

    HTTPRequest httpReq;
    httpReq.setMethod(HTTP::GET);
    httpReq.setURL("http://127.0.0.1:8080/");
    //httpReq.print();
    
    for (int n=0; n<UHTTP_HTTP_SERVER_TEST_LOOP_COUNT; n++) {
        HTTPResponse *httpRes = httpReq.post();
        BOOST_CHECK_EQUAL(httpRes->getStatusCode(), 200);
        string httpResContent = httpRes->getContent();
        BOOST_CHECK(0 < httpResContent.length());
        BOOST_CHECK_EQUAL(httpResContent.compare(UHTTP_HTTP_SERVER_TEST_CONTENT), 0);
        //httpRes->print();
    }
    
    BOOST_CHECK(httpServer.stop());
}

void HTTPSimpleRequestListener::httpRequestRecieved(HTTPRequest *httpReq)
{
     if (httpReq->isGetRequest() == false) {
        httpReq->returnBadRequest();
        return;
     }

	std::string uri;
	httpReq->getURI(uri);
	if (uri.length() <= 0) {
		httpReq->returnBadRequest();
		return;
	}

    std::string msg = UHTTP_HTTP_SERVER_TEST_CONTENT;

	HTTPResponse httpRes;
	httpRes.setStatusCode(HTTP::OK_REQUEST);
	httpRes.setContent(msg);
	httpReq->post(&httpRes);
}
