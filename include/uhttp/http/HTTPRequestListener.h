/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _UHTTP_HTTPREQUESTLISTENER_H_
#define _UHTTP_HTTPREQUESTLISTENER_H_

#include <uhttp/http/HTTPRequest.h>
#include <uhttp/util/Listener.h>

namespace uHTTP {
    
class HTTPRequestListener : public Listener {
public:
  virtual ::uHTTP::HTTP::StatusCode httpRequestRecieved(::uHTTP::HTTPRequest *httpReq) = 0;
};

}

#endif
