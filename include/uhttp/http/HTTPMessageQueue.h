/******************************************************************
*
*uHTTP for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _UHTTP_HTTPMESSAGEQUEUE_H_
#define _UHTTP_HTTPMESSAGEQUEUE_H_

#include <queue>

#include <uhttp/net/Socket.h>
#include <uhttp/util/Mutex.h>
#include <uhttp/util/MessageQueue.h>

namespace uHTTP {

class HTTPMessage : public Message {
  
public:
  
  HTTPMessage(Socket *socket) {
    this->socket = socket;
  }

  Socket *getSocket() {
    return this->socket;
  }
  
private:
  
  Socket *socket;
};

class HTTPMessageQueue : private MessageQueue {
  
public:
  
  HTTPMessageQueue();
  ~HTTPMessageQueue();
  
  bool pushMessage(HTTPMessage *httpMsg);
  bool waitMessage(HTTPMessage **httpMsg, time_t timeoutSec = 0);
  bool clear();
};

}

#endif
