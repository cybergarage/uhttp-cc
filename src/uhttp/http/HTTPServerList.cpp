/******************************************************************
 *
 * uHTTP for C++
 *
 * Copyright (C) Satoshi Konno 2002-2013
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#include <uhttp/http/HTTPServerList.h>
#include <uhttp/util/StringUtil.h>
#include <uhttp/util/Debug.h>

#include <sstream>

using namespace std;
using namespace uHTTP;

////////////////////////////////////////////////
//  Constructor
////////////////////////////////////////////////

HTTPServerList::HTTPServerList() {
}

HTTPServerList::~HTTPServerList() {
  stop();
  close();
}

////////////////////////////////////////////////
//  addRequestListener
////////////////////////////////////////////////

void HTTPServerList::addRequestListener(HTTPRequestListener *listener) {
  int nServers = size();
  for (int n = 0; n < nServers; n++) {
    HTTPServer *server = getHTTPServer(n);
    server->addRequestListener(listener);
  }
}

////////////////////////////////////////////////
//  open/close
////////////////////////////////////////////////

void HTTPServerList::close() {
  int nServers = size();
  for (int n = 0; n < nServers; n++) {
    HTTPServer *server = getHTTPServer(n);
    server->close();
  }
  clear();
}

bool HTTPServerList::open(int port) {
  bool ret = true;
  int nHostAddrs = GetNHostAddresses();
  for (int n = 0; n < nHostAddrs; n++) {
    string buf;
    const char *bindAddr = GetHostAddress(n, buf);
    HTTPServer *httpServer = new HTTPServer();
    // Thanks for Ilkka Poutanen and Stefano Lenzi (07/16/04)
    if (httpServer->open(port, bindAddr) == false) {
      string msg;
      string ibuf;
      msg += "Couldn't bind to ";
      msg += bindAddr;
      msg += ":";
      msg += Integer2String(port, ibuf);;
      Debug::warning(msg.c_str());
      ret = false;
      continue;
    }
    add(httpServer);
  }
  return ret;
}

////////////////////////////////////////////////
//  start/stop
////////////////////////////////////////////////

void HTTPServerList::start() {
  int nServers = size();
  for (int n = 0; n < nServers; n++) {
    HTTPServer *server = getHTTPServer(n);
    server->start();
  }
}

void HTTPServerList::stop() {
  int nServers = size();
  for (int n = 0; n < nServers; n++) {
    HTTPServer *server = getHTTPServer(n);
    server->stop();
  }
}

////////////////////////////////////////////////
// clear
////////////////////////////////////////////////

void HTTPServerList::clear() {
  int nServers = size();
  for (int n = 0; n < nServers; n++) {
    HTTPServer *server = getHTTPServer(n);
    delete server;
  }
  Vector::clear();
}
