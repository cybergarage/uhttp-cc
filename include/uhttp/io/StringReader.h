/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/


#ifndef _CIO_STRINGREADER_H_
#define _CIO_STRINGREADER_H_

#include <string>

#include <uhttp/io/Reader.h>
#include <uhttp/io/InputStream.h>

namespace uHTTP {

class StringReader : public Reader
{
	std::string buf;
	int pos;

public:

	StringReader(const std::string &str);
	
	int read(std::string &b, int len);
	
	long skip(long n);

	void unread(std::string &b, int off, int len)
	{
		// Not Implemented yet.
	}

	void close()
	{
	}
};

}

#endif
