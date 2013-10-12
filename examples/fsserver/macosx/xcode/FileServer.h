/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _UHTTP_FILESERVER_H_
#define _UHTTP_FILESERVER_H_

#include <uhttp/HTTP.h>

class FileServer : public uHTTP::HTTPServer
{

public:
	
	FileServer();
	~FileServer();

    bool start();
    bool stop();

    void httpRequestRecieved(uHTTP::HTTPRequest *httpReq);
};

#endif
