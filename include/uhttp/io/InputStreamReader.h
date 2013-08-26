/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _CIO_INPUTSTREAMREADER_H_
#define _CIO_INPUTSTREAMREADER_H_

#include <uhttp/io/Reader.h>
#include <uhttp/io/InputStream.h>

namespace uHTTP {

class InputStreamReader : public Reader
{
	InputStream *in;

public:

	InputStreamReader(InputStream *in)
	{
		this->in = in;
	}

	virtual ~InputStreamReader()
	{
	}

	int read(std::string &b, int len)
	{
		return in->read(b, len);
	}

	long skip(long n)
	{
		return in->skip(n);
	}

	void unread(std::string &b, int off, int len)
	{
		in->unread(b, off, len);
	}

	void unread(std::string &b, int len)
	{
		in->unread(b, len);
	}

	void unread(std::string &b)
	{
		in->unread(b);
	}

	void unread(char c)
	{
		in->unread(c);
	}
	
	void close()
	{
		in->close();
	}
};

}

#endif
