/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _CIO_READER_H_
#define _CIO_READER_H_

namespace uHTTP {

class Reader
{

public:

	Reader()
	{
	}

	virtual ~Reader()
	{
	}

	virtual int read(std::string &b, int len) = 0;

	virtual long skip(long n) = 0;

	virtual void unread(std::string &b, int off, int len) = 0;  

	void unread(std::string &b, int len)
	{
		 unread(b, 0, len);  
	}

	void unread(char c)
	{
		std::string b;
		b.append(&c, 0, 1);
		unread(b, 0, 1);  
	}
	
	virtual void close() = 0;

};

}

#endif

