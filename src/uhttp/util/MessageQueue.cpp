/******************************************************************
*
*uHTTP for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <string.h>
#include <unistd.h>
#include <sys/msg.h>

#include <uhttp/util/MessageQueue.h>

uHTTP::MessageQueue::MessageQueue() {
}

uHTTP::MessageQueue::~MessageQueue() {
}

bool uHTTP::MessageQueue::pushMessage(Message *message) {
  this->mutex.lock();
  push(message);
  this->mutex.unlock();

  return true;
}

bool uHTTP::MessageQueue::popMessage(Message **message) {
  if (empty())
    return false;

  this->mutex.lock();
  *message = front();
  pop();
  this->mutex.unlock();

  return true;
}
