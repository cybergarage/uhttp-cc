/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/


#ifndef _CUTIL_VECTOR_H_
#define _CUTIL_VECTOR_H_

#include <vector>
#include <stdlib.h>

namespace uHTTP {
class Vector {
private:

  std::vector<void *> vec;

 public:
  Vector() {
  }

  bool add(void *obj) {
    if (0 <= indexOf(obj))
      return false;
    vec.push_back(obj);
    return true;
  }

  bool remove(void *obj) {
    int idx = indexOf(obj);
    if (idx < 0)
      return false;
    vec.erase(vec.begin() + idx);
    return true;
  }

  int indexOf(void *obj) {
    int cnt = size();
    for (int n = 0; n < cnt; n++) {
      //if (obj == ((void *)at(n)))
      if (obj == (void *)(vec[n]))
        return n;
    }
    return -1;
  }

  void *get(int index) 
  {
    if (index < 0)
      return NULL;
    if (size() < (index+1))
      return NULL;
    return (void *)vec[index];
    //return (void *)at(index);
  }

  bool insertAt(void *obj, int index) {
    if (0 <= indexOf(obj))
      return false;
    vec.insert(vec.begin() + index, obj);
    return true;
  }

  int size() {
    return (int)vec.size();
  }

  void clear() {
    vec.clear();
  }
};

}

#endif
