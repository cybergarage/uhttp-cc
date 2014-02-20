/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <uhttp/io/File.h>
#include <uhttp/io/FileList.h>

using namespace uHTTP;

////////////////////////////////////////////////
//  Methods
////////////////////////////////////////////////

void FileList::clear()  {
  int nNode = size();
  for (int n = 0; n < nNode; n++) {
    File *file = getFile(n);
    delete file;
  }
  Vector::clear();
}


