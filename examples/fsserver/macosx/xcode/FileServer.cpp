/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <fstream>

#include "FileServer.h"

////////////////////////////////////////////////
//	Constructor
////////////////////////////////////////////////
	
FileServer::FileServer()
{
    setPort(uHTTP::HTTP::DEFAULT_PORT);
    setRootDirectory(".");
    setVerbose(false);
    addRequestListener(this);
}

FileServer::~FileServer()
{
}

////////////////////////////////////////////////
//	HTTP Server	
////////////////////////////////////////////////

void FileServer::httpRequestRecieved(uHTTP::HTTPRequest *httpReq)
{
    if (isVerbose()) {
        std::string firstHeader;
        std::cout << "> " << httpReq->getRequestLine(firstHeader) <<  std::endl;
        for (uHTTP::HTTPHeaderList::iterator header = httpReq->getHeaders().begin(); header != httpReq->getHeaders().end(); header++) {
            std::cout << "> " << (*header)->getName() << " : " << (*header)->getValue() << std::endl;
        }
    }
    
	if (!httpReq->isGetRequest()) {
        httpReq->returnBadRequest();
		return;
	}

    uHTTP::URI reqUri;
    httpReq->getURI(reqUri);
  
    std::string systemPath;
    systemPath.append(getRootDirectory());
    systemPath.append(reqUri.getPath());
    
    std::ifstream contentFs(systemPath.c_str(), std::ifstream::in | std::ifstream::binary);
    if (!contentFs.is_open()) {
        httpReq->returnNotFound();
        return;
    }

    size_t fileSize = (size_t)contentFs.seekg(0, std::ios::end).tellg();
    contentFs.seekg(0, std::ios::beg);

    bool isBinary = false;
    while (contentFs.good()) {
        char c = contentFs.get();
        if (contentFs.good()) {
            if (c == 0) {
                isBinary = true;
                break;
            }
        }
    }
    contentFs.seekg(0, std::ios::beg);
    
	uHTTP::HTTPResponse httpRes;
	httpRes.setStatusCode(uHTTP::HTTP::OK_REQUEST);
	httpRes.setContentType(isBinary ? "application/octet-stream" : "text/plain");
	httpRes.setContentLength(fileSize);

    if (verboseMode) {
        std::cout << "< " << httpRes.getFirstLine() << std::endl;
        for (uHTTP::HTTPHeaderList::iterator header = httpRes.getHeaders().begin(); header != httpRes.getHeaders().end(); header++) {
            std::cout << "< " << (*header)->getName() << " : " << (*header)->getValue() << std::endl;
        }
    }
    
	httpReq->post(&httpRes);

    if (httpReq->isHeadRequest()) {
        return;
    }
    
    uHTTP::HTTPSocket *httpSocket = httpReq->getSocket();
        
    while (contentFs.good()) {
        char c = contentFs.get();
        if (contentFs.good()) {
            httpSocket->post(c);
            if (isVerbose())
                std::cout << c;
        }
    }

    contentFs.close();
}

////////////////////////////////////////////////
//	start
////////////////////////////////////////////////

bool FileServer::start()
{
	stop();

    if (!open(getPort()))
        return false;
    
    return HTTPServer::start();
}

////////////////////////////////////////////////
//	stop
////////////////////////////////////////////////

bool FileServer::stop()
{
    return HTTPServer::stop();
}
