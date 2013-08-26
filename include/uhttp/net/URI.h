/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _CNET_URI_H_
#define _CNET_URI_H_

#include <string>

namespace uHTTP {

const int URI_KNKOWN_PORT = -1;

class URI {

protected:

	std::string uriStr;
	std::string protocol;
	std::string user;
	std::string password;
	std::string host;
	int port;
	std::string path;
	std::string query;
	std::string fragment;

public:
    
    static const char *HTTP;
    static const char *HTTPS;
    
    static int HTTP_PORT;
    static int HTTPS_PORT;
    
public:

	static const char *PROTOCOL_DELIM;
	static const char *USER_DELIM;
	static const char *COLON_DELIM;
	static const char *SLASH_DELIM;
	static const char *SBLACET_DELIM;
	static const char *EBLACET_DELIM;
	static const char *SHARP_DELIM;
	static const char *QUESTION_DELIM;
	
public:

	URI();
	URI(const std::string &uriStr);

	bool IsAbsoluteURI();

	void setString(const std::string &uriStr);

	const char *getSting()
	{
		return uriStr.c_str();
	}

	const char *getProtocol()
	{
		return protocol.c_str();
	}

    bool hasProtocol()
    {
        return (0 < protocol.length());
    }
    
    bool isProtocol(const std::string &protocolPrefix)
    {
        return (protocol.compare(protocolPrefix) == 0) ? true : false;
    }

    bool isHTTP()
    {
        return isProtocol(HTTP);
    }

    bool isHTTPS()
    {
        return isProtocol(HTTPS);
    }
    
	const char *getUser()
	{
		return user.c_str();
	}

	const char *getPassword()
	{
		return password.c_str();
	}

	const char *getHost()
	{
		return host.c_str();
	}

	int getPort()
	{
		return port;
	}

	const char *getPath()
	{
		return path.c_str();
	}

	const char *getQuery()
	{
		return query.c_str();
	}

	const char *getFragment()
	{
		return fragment.c_str();
	}

	void print();
};

}

#endif
