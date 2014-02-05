/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/


#ifndef _CNET_SOCKET_H_
#define _CNET_SOCKET_H_

#include <uhttp/net/SocketImp.h>

namespace uHTTP {
class Socket : public SocketImp {
 public:
  static ssize_t GetInstanceCount();
  
 public:
  Socket();
  ~Socket();

  bool listen();

  bool bind(int port, const std::string &addr);

  bool accept(Socket *socket);

  bool connect(const std::string &addr, int port);

  ssize_t send(const char *cmd, size_t cmdLen);
  ssize_t send(const std::string &cmd);
  ssize_t send(const char c);

  ssize_t recv(char *buffer, size_t bufferLen);

private:
  
#if defined(ITRON)
  static const int WINDOW_BUF_SIZE;
  UH *sendWinBuf;
  UH *recvWinBuf;
#endif

#if defined(ITRON)
  void initWindowBuffer();
#endif
  
};

}

#endif
