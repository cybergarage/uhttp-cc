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

template <typename T> class Vector : public std::vector<T*> {
private:

 public:
    
  Vector() {
    setWeekContainer(false);
  }

  ~Vector() {
    clear();
  }
  
  void setWeekContainer(bool flag) {
    this->weekContainerFlag = flag;
  }
  
  bool isWeekContainer() {
    return this->weekContainerFlag;
  }
  
  bool add(T *obj) {
    if (0 <= indexOf(obj))
      return false;
    std::vector<T*>::push_back(obj);
    return true;
  }

  bool remove(T *obj) {
    ssize_t idx = indexOf(obj);
    if (idx < 0)
      return false;
    typename std::vector<T*>::iterator objIt = std::vector<T*>::begin() + idx;
    if (!isWeekContainer()) {
      delete *objIt;
    }
    std::vector<T*>::erase(objIt);
    return true;
  }

  ssize_t indexOf(void *obj) {
    size_t cnt = std::vector<T*>::size();
    for (size_t n = 0; n < cnt; n++) {
      if (obj == ((T *)std::vector<T*>::at(n)))
        return n;
    }
    return -1;
  }

  T *get(size_t index) {
    if (std::vector<T*>::size() < (index+1))
      return NULL;
    return std::vector<T*>::at(index);
  }

  bool insertAt(T *obj, size_t index) {
    if (0 <= indexOf(obj))
      return false;
    std::vector<T*>::insert(std::vector<T*>::begin() + index, obj);
    return true;
  }

  void clear()
  {
    if (!isWeekContainer()) {
      for (typename std::vector<T*>::iterator objIt = std::vector<T*>::begin() ; objIt != std::vector<T*>::end(); ++objIt) {
        delete *objIt;
      }
    }
    std::vector<T*>::clear();
  }
  
private:
  
  bool weekContainerFlag;
  
};

}

#endif
