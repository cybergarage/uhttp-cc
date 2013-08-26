/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/


#include <uhttp/net/SocketInputStream.h>
#include <uhttp/util/TimeUtil.h>

using namespace uHTTP;
using namespace uHTTP;

////////////////////////////////////////////////
//	Constructor
////////////////////////////////////////////////

SocketInputStream::SocketInputStream(Socket *sock)
{
	this->sock = sock;
	this->inBuf = new char[SOCKET_INBUF_SIZE];
}

////////////////////////////////////////////////
//	Destructor
////////////////////////////////////////////////

SocketInputStream::~SocketInputStream()
{
	delete[] this->inBuf;
}

////////////////////////////////////////////////
//	read
////////////////////////////////////////////////

int SocketInputStream::read(std::string &b, int len)
{
    if (!this->inBuf)
        return 0;
    
	int readCnt = 0;
	int retryCnt = 0;

	int unputBufLen = unputBuf.length();
	if (0 < unputBufLen) {
		int cpyCnt = (len < unputBufLen) ? len : unputBufLen;
		readCnt = cpyCnt;
		b.append(unputBuf, 0, cpyCnt);
		unputBuf = unputBuf.substr(cpyCnt, unputBufLen - cpyCnt);
	}

	while (readCnt < len) {
		int readSize = len - readCnt;
		if (SOCKET_INBUF_SIZE < readSize)
			readSize = SOCKET_INBUF_SIZE;
		int readLen = sock->recv(this->inBuf, readSize);
		if (readLen <= 0) {
			Wait(SOCKET_RECV_WAIT_TIME);
			retryCnt++;
			if (SOCKET_RECV_RETRY_CNT < retryCnt)
				break;
		}
		else {
			b.append(this->inBuf, 0, readLen);
			readCnt += readLen;
		}
	}
	return readCnt;
}

////////////////////////////////////////////////
//	read
////////////////////////////////////////////////

int SocketInputStream::read(char *b, int len)
{
    if (!this->inBuf)
        return 0;
    
	int readCnt = 0;
	int retryCnt = 0;

	while (readCnt < len) {
		int readSize = len - readCnt;
		int readLen = sock->recv(b+readCnt, readSize);
		if (readLen <= 0) {
			Wait(SOCKET_RECV_WAIT_TIME);
			retryCnt++;
			if (SOCKET_RECV_RETRY_CNT < retryCnt)
				break;
		}
		readCnt += readLen;
	}
	return readCnt;
}

////////////////////////////////////////////////
//	unread
////////////////////////////////////////////////

void SocketInputStream::unread(std::string &b, int off, int len)
{
	unputBuf.append(b.substr(off, len));
}

////////////////////////////////////////////////
//	skip
////////////////////////////////////////////////

long SocketInputStream::skip(long n)
{
    if (!this->inBuf)
        return 0;
    
	long skippedByte = 0;
	int retryCnt = 0;
	while (n < skippedByte) {
		long readByte = n - skippedByte;
		if (SOCKET_INBUF_SIZE < readByte)
			readByte = SOCKET_INBUF_SIZE;
		int readLen = sock->recv(this->inBuf, (int)readByte);
		if (readLen <= 0) {
			Wait(SOCKET_RECV_WAIT_TIME);
			retryCnt++; 
			if (SOCKET_RECV_RETRY_CNT < retryCnt)
				break;
		}
		else
			skippedByte += readLen;
	}
	return skippedByte;
}

////////////////////////////////////////////////
//	close
////////////////////////////////////////////////

void SocketInputStream::close()
{
	sock->close();
}
