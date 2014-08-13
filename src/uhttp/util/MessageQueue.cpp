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
  this->sem = new Semaphore(0);
  this->mutex = new Mutex();
}

uHTTP::MessageQueue::~MessageQueue() {
  clear();
  delete this->sem;
  delete this->mutex;
}

bool uHTTP::MessageQueue::pushMessage(Message *message) {
  this->mutex->lock();
  
  push(message);
  this->sem->post();
  
  this->mutex->unlock();

  return true;
}

bool uHTTP::MessageQueue::popMessage(Message **message) {
  *message = NULL;
  
  if (empty())
    return false;

  *message = front();
  pop();
  
  return true;
}

bool uHTTP::MessageQueue::waitMessage(Message **message, time_t timeoutSec) {
  if (!this->sem->wait(timeoutSec))
    return false;

  this->mutex->lock();
  
  bool popSucces = popMessage(message);
  
  this->mutex->unlock();
  
  return popSucces;
}

bool uHTTP::MessageQueue::clear() {
  
  Message *message;
  while (popMessage(&message)) {
    delete message;
  }
  
  return true;
}
