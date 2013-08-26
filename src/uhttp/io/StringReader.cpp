/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/


#include <uhttp/io/StringReader.h>

using namespace uHTTP;

StringReader::StringReader(const std::string &str)
{
	buf = str;
	pos = 0;
}

int StringReader::read(std::string &b, int len)
{
	int bufLen = buf.length() - pos;
	if (bufLen <= 0)
		return 0;
	int copyLen = (len < bufLen) ? len : bufLen;
	b.append(buf, pos, copyLen);
	pos += copyLen;
	return copyLen;
}

long StringReader::skip(long skipLen)
{
	pos += skipLen;
	return skipLen;
}
