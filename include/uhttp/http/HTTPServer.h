/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _CHTTP_HTTPSERVER_H_
#define _CHTTP_HTTPSERVER_H_

#include <uhttp/net/ServerSocket.h>
#include <uhttp/util/Thread.h>
#include <uhttp/util/ListenerList.h>
#include <uhttp/http/HTTPRequest.h>
#include <uhttp/http/HTTPRequestListener.h>

#include <string>

namespace uHTTP {
class HTTPServer : public uHTTP::Thread {
  uHTTP::ServerSocket *serverSock;
  uHTTP::ListenerList httpRequestListenerList;

  bool bind(int port, const std::string &addr = "");
  bool accept(uHTTP::Socket *socket);
  bool isOpened();

  uHTTP::ServerSocket *getServerSock() {
    return serverSock;
  }

public:
  
  HTTPServer();
  ~HTTPServer();

  ////////////////////////////////////////////////
  //  open/close
  ////////////////////////////////////////////////
  
  bool open(int port, const std::string &addr = "");
  bool close();
  
  ////////////////////////////////////////////////
  //  httpRequest
  ////////////////////////////////////////////////
     
  void addRequestListener(HTTPRequestListener *listener) {
    httpRequestListenerList.add(listener);
  }    

  void removeRequestListener(HTTPRequestListener *listener) {
    httpRequestListenerList.remove(listener);
  }    

  HTTP::StatusCode performRequestListener(HTTPRequest *httpReq) {
    HTTP::StatusCode lastStatusCode = HTTP::INTERNAL_SERVER_ERROR;
    int listenerSize = httpRequestListenerList.size();
    for (int n = 0; n < listenerSize; n++) {
      HTTPRequestListener *listener = (HTTPRequestListener *)httpRequestListenerList.get(n);
      lastStatusCode = listener->httpRequestRecieved(httpReq);
      if (lastStatusCode == HTTP::OK_REQUEST)
        break;
    }
    return lastStatusCode;
  }    

  ////////////////////////////////////////////////
  //  run  
  ////////////////////////////////////////////////

  bool start();
  void run();
  bool stop();

};

const char *GetServerName(std::string &buf);

}

#endif
