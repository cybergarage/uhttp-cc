/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/


#include <uhttp/net/Socket.h>
#include <uhttp/http/HTTPServerThread.h>

#include <sstream>

using namespace uHTTP;
using namespace uHTTP;

////////////////////////////////////////////////
//  Constructor
////////////////////////////////////////////////
  
HTTPServerThread::HTTPServerThread(HTTPServer *server, Socket *sock) {
  clientSock = sock;
  httpServer = server;
}

HTTPServerThread::~HTTPServerThread() {
}

////////////////////////////////////////////////
//  run  
////////////////////////////////////////////////

void HTTPServerThread::run() {
  HTTPSocket httpSock(clientSock);
  if (httpSock.open() == false) {
    delete clientSock;
    delete this;
    return;
  }
  HTTPRequest httpReq;
  httpReq.setSocket(&httpSock);
  while (httpReq.read() == true) {
    httpServer->performRequestListener(&httpReq);
    if (httpReq.isKeepAlive() == false)
      break;
  }
  httpSock.close();
  delete clientSock;
  delete this;
}
