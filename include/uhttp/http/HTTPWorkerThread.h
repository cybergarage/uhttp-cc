/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/


#ifndef _CHTTP_HTTPWORKERTHREAD_H_
#define _CHTTP_HTTPWORKERTHREAD_H_

#include <uhttp/util/Thread.h>
#include <uhttp/http/HTTPServer.h>

namespace uHTTP {
  
class HTTPWorkerThread : public uHTTP::Thread {
  uHTTP::HTTPServer *httpServer;

public:
  
  HTTPWorkerThread(uHTTP::HTTPServer *server);
  ~HTTPWorkerThread();

  ////////////////////////////////////////////////
  //  run  
  ////////////////////////////////////////////////

  void run();

};


}

#endif
