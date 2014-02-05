/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/


#ifndef _CHTTP_HTTPREQUESTLISTENER_H_
#define _CHTTP_HTTPREQUESTLISTENER_H_

#include <uhttp/http/HTTPRequest.h>

namespace uHTTP {
class HTTPRequestListener {
public:
  virtual HTTP::StatusCode httpRequestRecieved(HTTPRequest *httpReq) = 0;
};

}

#endif
