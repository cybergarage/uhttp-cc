/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <string.h>
#include <uhttp/io/StringBufferInputStream.h>

using namespace uHTTP;

StringBufferInputStream::StringBufferInputStream(const std::string &str)
{
	buf = str;
	pos = 0;
}

int StringBufferInputStream::read(std::string &b, int len)
{
	size_t bufLen = buf.length() - pos;
	if (bufLen <= 0)
		return 0;
	size_t copyLen = (len < bufLen) ? len : bufLen;
	b.append(buf, pos, copyLen);
	pos += copyLen;
	return copyLen;
}

int StringBufferInputStream::read(char *b, int len)
{
	size_t bufLen = buf.length() - pos;
	if (bufLen <= 0)
		return 0;
	size_t copyLen = (len < bufLen) ? len : bufLen;
	strncpy(b, (buf.c_str() + pos), copyLen);
	pos += copyLen;
	return copyLen;
}

long StringBufferInputStream::skip(long n)
{
	pos += n;
	return n;
}

