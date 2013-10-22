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

class FileServer : public uHTTP::HTTPServer, public uHTTP::HTTPRequestListener
{

    std::string rootDirectory;
    int port;
    bool verboseMode;
    
public:
	
	FileServer();
	~FileServer();

    void setRootDirectory(const std::string &value) {
        this->rootDirectory = value;
    }
    
    const char *getRootDirectory() {
        return this->rootDirectory.c_str();
    }
    
    void setPort(int value) {
        this->port = value;
    }
    
    int getPort() {
        return this->port;
    }
    
    void setVerbose(bool value) {
        this->verboseMode = value;
    }
    
    bool isVerbose() {
        return this->verboseMode;
    }
    
    bool start();
    bool stop();

    void httpRequestRecieved(uHTTP::HTTPRequest *httpReq);
};

#endif
