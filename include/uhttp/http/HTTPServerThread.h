/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/


#ifndef _CHTTP_HTTPSERVERTHREAD_H_
#define _CHTTP_HTTPSERVERTHREAD_H_

#include <uhttp/util/Thread.h>
#include <uhttp/http/HTTPServer.h>

namespace uHTTP {
class HTTPServerThread : public uHTTP::Thread {
  uHTTP::Socket *clientSock;
  uHTTP::HTTPServer *httpServer;

public:
  
  HTTPServerThread(uHTTP::HTTPServer *server, uHTTP::Socket *sock);
  ~HTTPServerThread();

  ////////////////////////////////////////////////
  //  run  
  ////////////////////////////////////////////////

  void run();

};


}

#endif
