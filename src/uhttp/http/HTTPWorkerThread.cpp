/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/


#include <uhttp/net/Socket.h>
#include <uhttp/http/HTTPWorkerThread.h>

#include <sstream>

using namespace uHTTP;

////////////////////////////////////////////////
//  Constructor
////////////////////////////////////////////////
  
HTTPWorkerThread::HTTPWorkerThread(HTTPServer *server) {
  httpServer = server;
}

HTTPWorkerThread::~HTTPWorkerThread() {
}

////////////////////////////////////////////////
//  run  
////////////////////////////////////////////////

void HTTPWorkerThread::run() {
  
  while (isRunnable()) {
    HTTPMessage *httpMsg;
    if (!httpServer->waitMessage(&httpMsg))
      break;
    
    Socket *clientSock = httpMsg->getSocket();
    if (!clientSock) {
      delete httpMsg;
      continue;
    }
    
    HTTPSocket *httpSock = new HTTPSocket(clientSock);
    if (!httpSock) {
      delete httpMsg;
      delete clientSock;
      continue;
    }
    
    if (httpSock->open() == false) {
      delete httpSock;
      delete httpMsg;
      delete clientSock;
      continue;
    }
    
    HTTPRequest *httpReq = new HTTPRequest();
    if (!httpReq) {
      delete httpSock;
      delete httpMsg;
      delete clientSock;
      continue;
    }
    httpReq->setSocket(httpSock);

    HTTP::StatusCode statusCode;
    while (httpReq->read() == true) {
      statusCode = httpServer->performRequestListener(httpReq);
      if (httpReq->isKeepAlive() == false)
        break;
    }
    
    if (statusCode != HTTP::PROCESSING) {
      delete httpReq;
    }

    delete httpMsg;
  }
}
