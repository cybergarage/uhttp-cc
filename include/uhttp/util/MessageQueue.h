/******************************************************************
*
*uHTTP for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _UHTTP_MESSAGEQUEUE_H_
#define _UHTTP_MESSAGEQUEUE_H_

#include <queue>

#include <uhttp/util/Mutex.h>
#include <uhttp/util/Semaphore.h>

namespace uHTTP {

class Message {
  
public:
  
  Message();
  virtual ~Message();
};

class MessageQueue : private std::queue<Message *> {
  
public:
  
  MessageQueue();
  virtual ~MessageQueue();
  
  bool pushMessage(Message *message);
  bool popMessage(Message **message);
  
private:
  
  void clear();

private:

  Mutex mutex;
};

}

#endif
