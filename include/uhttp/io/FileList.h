/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _CIO_FILELIST_H_
#define _CIO_FILELIST_H_

#include <uhttp/util/Vector.h>

namespace uHTTP {
class File;

class FileList : public uHTTP::Vector  {
public:
  ////////////////////////////////////////////////
  //  Constructor
  ////////////////////////////////////////////////
  
  FileList() 
  {
  }

  ~FileList() 
  {
    clear();
  }
  
  ////////////////////////////////////////////////
  //  Methods
  ////////////////////////////////////////////////

 public:
  File *getFile(int n) {
    return (File*)Vector::get(n);
  }

  ////////////////////////////////////////////////
  // clear
  ////////////////////////////////////////////////

 public:
  void clear();
};

}

#endif



