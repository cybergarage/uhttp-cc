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

#define UHTTP_HTTP_SERVER_TEST_LOOP_COUNT 100
#define UHTTP_HTTP_SERVER_TEST_CONTENT "123456789abcedfghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define UHTTP_HTTP_SERVER_TEST_PARAM_NAME "param"

class HTTPSimpleRequestListener : public HTTPRequestListener
{
  uHTTP::HTTP::StatusCode httpRequestRecieved(HTTPRequest *httpReq);
};

BOOST_AUTO_TEST_CASE(HTTPSimpleServer)
{
  HTTPServer httpServer;
  HTTPSimpleRequestListener httpSimpleReqListener;
  httpServer.addRequestListener(&httpSimpleReqListener);

  Random rand (1000, 10000);
  int httpPort = rand.rand();
  
  BOOST_CHECK_EQUAL(Socket::GetInstanceCount(), 0);
  
  BOOST_CHECK(httpServer.open(httpPort));
  BOOST_CHECK(httpServer.start());
  
  for (int n=0; n<UHTTP_HTTP_SERVER_TEST_LOOP_COUNT; n++) {
    HTTPRequest httpReq;
    httpReq.setMethod(HTTP::GET);
    char httpReqURL[64];
    snprintf(httpReqURL, sizeof(httpReqURL), "http://127.0.0.1:%d/?%s=%d", httpPort, UHTTP_HTTP_SERVER_TEST_PARAM_NAME, n);
    httpReq.setURL(httpReqURL);
    
    string httpReqStr;
    httpReq.toString(httpReqStr);
    BOOST_MESSAGE(httpReqStr);
    
    HTTPResponse *httpRes = httpReq.post();
    BOOST_CHECK_EQUAL(httpRes->getStatusCode(), 200);
    string httpResContent = httpRes->getContent();
    BOOST_CHECK(0 < httpResContent.length());

    std::stringstream msgBuf;
    msgBuf << UHTTP_HTTP_SERVER_TEST_CONTENT << n;
    BOOST_CHECK_EQUAL(httpResContent.compare(msgBuf.str()), 0);
    
    string httpResStr;
    httpRes->toString(httpResStr);
    BOOST_MESSAGE(httpResStr);
  }
  
  BOOST_CHECK(httpServer.close());
  BOOST_CHECK(httpServer.stop());
  
  SocketList *socketList = Socket::GetInstanceList();
  size_t socketListCnt = socketList->size();
  for (size_t n=0; n<socketListCnt; n++) {
    SocketCore *socket = socketList->get(n);
    const type_info& socketInfo = typeid(*socket);
    BOOST_MESSAGE("Opened Sockets [" << n << "] : " << socketInfo.name() << "(" << socket->getSocket()) << ")";
  }
  
  BOOST_CHECK_EQUAL(Socket::GetInstanceCount(), 0);
}

uHTTP::HTTP::StatusCode HTTPSimpleRequestListener::httpRequestRecieved(HTTPRequest *httpReq)
{
   if (httpReq->isGetRequest() == false) {
      return httpReq->returnBadRequest();
   }

  std::string uri;
  httpReq->getURI(uri);
  if (uri.length() <= 0) {
    return httpReq->returnBadRequest();
  }

  string paramStr;
  BOOST_CHECK(httpReq->getParameterValue(UHTTP_HTTP_SERVER_TEST_PARAM_NAME, &paramStr));

  std::string msg = UHTTP_HTTP_SERVER_TEST_CONTENT;
  msg.append(paramStr);
  
  HTTPResponse httpRes;
  httpRes.setStatusCode(HTTP::OK_REQUEST);
  httpRes.setContent(msg);
  httpReq->post(&httpRes);

  return uHTTP::HTTP::OK_REQUEST;
}
