/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002
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
    ssize_t idx = indexOf(obj);
    if (idx < 0)
      return false;
    vec.erase(vec.begin() + idx);
    return true;
  }

  ssize_t indexOf(void *obj) {
    size_t cnt = size();
    for (int n = 0; n < cnt; n++) {
      //if (obj == ((void *)at(n)))
      if (obj == (void *)(vec[n]))
        return n;
    }
    return -1;
  }

  void *get(size_t index)
  {
    if (size() < (index+1))
      return NULL;
    return (void *)vec[index];
  }

  bool insertAt(void *obj, size_t index) {
    if (0 <= indexOf(obj))
      return false;
    vec.insert(vec.begin() + index, obj);
    return true;
  }

  size_t size() {
    return (int)vec.size();
  }

  void clear() {
    vec.clear();
  }
};

}

#endif
