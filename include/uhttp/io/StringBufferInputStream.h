/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _CIO_STRINGBUFFERINPUTSTREAM_H_
#define _CIO_STRINGBUFFERINPUTSTREAM_H_

#include <stdio.h>
#include <string>
#include <uhttp/io/File.h>
#include <uhttp/io/InputStream.h>

namespace uHTTP {

class StringBufferInputStream : public InputStream
{
	std::string buf;
	long pos;

public:

	StringBufferInputStream(const std::string &str);

	int read(std::string &b, int len);
	int read(char *b, int len);

	void unread(std::string &b, int off, int len)
	{
		// Not Implemented yet
	}

	long skip(long n);

	void close()
	{
	}
};

}

#endif
