/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/


#ifndef _CIO_FILEINPUTSTREAM_H_
#define _CIO_FILEINPUTSTREAM_H_

#include <stdio.h>
#include <string>
#include <uhttp/io/File.h>
#include <uhttp/io/InputStream.h>

namespace uHTTP {

const long FILE_INBUF_SIZE = 512*1024;

class FileInputStream : public InputStream
{
	FILE *fp;
	char *inBuf;

public:

	FileInputStream(File *file, const std::string &mode);
	~FileInputStream();

	int read(std::string &b, int len);
	int read(char *b, int len);

	void unread(std::string &b, int off, int len);  // Not Implemented

	long skip(long n);

	void close();
};

}

#endif
