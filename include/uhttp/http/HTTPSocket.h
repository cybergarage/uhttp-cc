/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/


#ifndef _CHTTP_HTTPSOCKET_H_
#define _CHTTP_HTTPSOCKET_H_

#include <uhttp/net/Socket.h>
#include <uhttp/io/InputStream.h>

namespace uHTTP {
class HTTPResponse;

class HTTPSocket {
  uHTTP::Socket *socket;
  
 public:
  ////////////////////////////////////////////////
  //  Constructor
  ////////////////////////////////////////////////
  
  HTTPSocket(uHTTP::Socket *socket);
  HTTPSocket(HTTPSocket *socket);
  ~HTTPSocket();
  
  ////////////////////////////////////////////////
  //  Socket
  ////////////////////////////////////////////////

  void setSocket(uHTTP::Socket *socket) {
    this->socket = socket;
  }

  uHTTP::Socket *getSocket() {
    return socket;
  }

  ////////////////////////////////////////////////
  //  local address/port
  ////////////////////////////////////////////////
  
 public:
  const char *getLocalAddress() {
    return getSocket()->getLocalAddress();  
  }

  int getLocalPort() {
    return getSocket()->getLocalPort();  
  }

  ////////////////////////////////////////////////
  //  open/close
  ////////////////////////////////////////////////

 public:
  bool open();
  bool close();
  
  ////////////////////////////////////////////////
  //  post
  ////////////////////////////////////////////////

private:

  bool post(HTTPResponse *httpRes, const std::string &content, size_t contentOffset, size_t contentLength, bool isOnlyHeader, bool isChunked);
  bool post(HTTPResponse *httpRes, uHTTP::InputStream *in, size_t contentOffset, size_t contentLength, bool isOnlyHeader, bool isChunked);

 public:
  bool post(HTTPResponse *httpRes, size_t contentOffset, size_t contentLength, bool isOnlyHeader, bool isChunked);
  bool post(HTTPResponse *httpRes);
  bool post(const std::string &content);
  bool post(const char c);
};

}

#endif

