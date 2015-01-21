/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _CUTIL_LISTENERLIST_H_
#define _CUTIL_LISTENERLIST_H_

#include <uhttp/util/Vector.h>

namespace uHTTP {

class Listener {
public:
    Listener() {
    }
    virtual ~Listener() {
    }
};

template <typename T> class ListenerList : public ::uHTTP::WeakVector<T> {

public:
    
  ListenerList() {
  }
};

}

#endif
