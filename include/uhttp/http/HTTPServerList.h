/******************************************************************
 *
 * uHTTP for C++
 *
 * Copyright (C) Satoshi Konno 2002
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#ifndef _UHTTP_HTTPSERVERLIST_H_
#define _UHTTP_HTTPSERVERLIST_H_

#include <uhttp/http/HTTPServer.h>
#include <uhttp/net/HostInterface.h>
#include <uhttp/util/Vector.h>

namespace uHTTP {
    
class HTTPServerList : public Vector<HTTPServer>  {
  ////////////////////////////////////////////////
  //  Constructor
  ////////////////////////////////////////////////
  
 public:
  HTTPServerList();
  ~HTTPServerList();

  ////////////////////////////////////////////////
  //  Methods
  ////////////////////////////////////////////////

 public:
  HTTPServer *getHTTPServer(size_t n) {
    return get(n);
  }

  void addRequestListener(HTTPRequestListener *listener);
  void removeRequestListener(HTTPRequestListener *listener);
  
  void setWorkerCount(size_t count);
  
  ////////////////////////////////////////////////
  //  open/close
  ////////////////////////////////////////////////

 public:
  bool close();
  bool open(int port);


  ////////////////////////////////////////////////
  //  start/stop
  ////////////////////////////////////////////////

 public:
  bool start();
  bool stop();
};

}

#endif
