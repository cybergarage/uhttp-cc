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
#include <sstream>

#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string.hpp>

#include <uhttp/HTTP.h>

using namespace std;
using namespace uHTTP;

//////////////////////////////////////////////////////////////////////
// Simple Request Listener
//////////////////////////////////////////////////////////////////////

#define UHTTP_HTTP_SERVER_TEST_LOOP_COUNT 100
#define UHTTP_HTTP_SERVER_TEST_CONTENT "123456789abcedfghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define UHTTP_HTTP_SERVER_TEST_PARAM_NAME "param"

class HTTPSimpleRequestListener : public HTTPRequestListener
{
public:
  HTTPSimpleRequestListener();
  
  uHTTP::HTTP::StatusCode httpRequestRecieved(HTTPRequest *httpReq);
};

HTTPSimpleRequestListener::HTTPSimpleRequestListener()
{
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

//////////////////////////////////////////////////////////////////////
// Simple Server
//////////////////////////////////////////////////////////////////////

static void RequestToHTTPServer(const std::string &ifaddr, int port)
{
  for (int n=0; n<UHTTP_HTTP_SERVER_TEST_LOOP_COUNT; n++) {
    HTTPRequest httpReq;
    httpReq.setMethod(HTTP::GET);
    char httpReqURL[64];
    snprintf(httpReqURL, sizeof(httpReqURL), "http://%s:%d/?%s=%d", ifaddr.c_str(), port, UHTTP_HTTP_SERVER_TEST_PARAM_NAME, n);
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
}

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
  
  const std::string ifaddr = "127.0.0.1";
  RequestToHTTPServer(ifaddr, httpPort);
  
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

BOOST_AUTO_TEST_CASE(HTTPSimpleServerList)
{
  BOOST_CHECK_EQUAL(Socket::GetInstanceCount(), 0);
  
  Random rand (1000, 10000);
  
  HTTPServerList httpServerList;
  BOOST_CHECK(httpServerList.open(rand.rand()));

  HTTPSimpleRequestListener httpSimpleReqListener;
  httpServerList.addRequestListener(&httpSimpleReqListener);
  
  BOOST_CHECK(httpServerList.start());
  
  size_t htttpServerCount = httpServerList.size();
  BOOST_CHECK(0 < htttpServerCount);
  for (size_t n= 0; n < htttpServerCount; n++) {
    std::shared_ptr<HTTPServer> httpServer = httpServerList.getHTTPServer(n);
    const std::string ifaddr = httpServer->getAddress();
    int httpPort = httpServer->getPort();
    RequestToHTTPServer(ifaddr, httpPort);
  }
  
  BOOST_CHECK(httpServerList.close());
  BOOST_CHECK(httpServerList.stop());
  
  BOOST_CHECK_EQUAL(Socket::GetInstanceCount(), 0);
}
