/******************************************************************
 *
 * uHTTP for C++
 *
 * Copyright (C) Satoshi Konno 2002
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/


#include <stdio.h>
#include <uhttp/util/Thread.h>

uHTTP::ThreadList::ThreadList() {
}

uHTTP::ThreadList::~ThreadList() {
}

bool uHTTP::ThreadList::start() {
  for (ThreadList::iterator thread = begin(); thread != end(); thread++) {
    (*thread)->start();
  }
  return true;
}

bool uHTTP::ThreadList::stop() {
  for (ThreadList::iterator thread = begin(); thread != end(); thread++) {
    (*thread)->stop();
  }
  return true;
}
