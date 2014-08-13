############################################################
#
# uHTTP for C++
#
# Copyright (C) Satoshi Konno 2003
#
############################################################

lib_LIBRARIES = libuhttp++.a

AM_CPPFLAGS = -I$(top_srcdir)/include

uhttpcc_sources = \
	../../src/uhttp/http/HTTP.cpp \
	../../src/uhttp/http/HTTPDate.cpp \
	../../src/uhttp/http/HTTPHeader.cpp \
	../../src/uhttp/http/HTTPMessageQueue.cpp \
	../../src/uhttp/http/HTTPPacket.cpp \
	../../src/uhttp/http/HTTPRequest.cpp \
	../../src/uhttp/http/HTTPResponse.cpp \
	../../src/uhttp/http/HTTPServer.cpp \
	../../src/uhttp/http/HTTPServerList.cpp \
	../../src/uhttp/http/HTTPSocket.cpp \
	../../src/uhttp/http/HTTPStatus.cpp \
	../../src/uhttp/http/HTTPWorkerThread.cpp \
	../../src/uhttp/io/BufferedReader.cpp \
	../../src/uhttp/io/File.cpp \
	../../src/uhttp/io/FileInputStream.cpp \
	../../src/uhttp/io/StringBufferInputStream.cpp \
	../../src/uhttp/io/StringReader.cpp \
	../../src/uhttp/net/DatagramSocket.cpp \
	../../src/uhttp/net/HostInterface.cpp \
	../../src/uhttp/net/MulticastSocket.cpp \
	../../src/uhttp/net/ServerSocket.cpp \
	../../src/uhttp/net/Socket.cpp \
	../../src/uhttp/net/SocketImp.cpp \
	../../src/uhttp/net/SocketInputStream.cpp \
	../../src/uhttp/net/SocketUtil.cpp \
	../../src/uhttp/net/URI.cpp \
	../../src/uhttp/net/URL.cpp \
	../../src/uhttp/util/Date.cpp \
	../../src/uhttp/util/Debug.cpp \
	../../src/uhttp/util/Log.cpp \
	../../src/uhttp/util/Logger.cpp \
	../../src/uhttp/util/LoggerFileTarget.cpp \
	../../src/uhttp/util/LoggerTarget.cpp \
	../../src/uhttp/util/LoggerTargetList.cpp \
	../../src/uhttp/util/Message.cpp \
	../../src/uhttp/util/MessageQueue.cpp \
	../../src/uhttp/util/Mutex.cpp \
	../../src/uhttp/util/Random.cpp \
	../../src/uhttp/util/Semaphore.cpp \
	../../src/uhttp/util/StringTokenizer.cpp \
	../../src/uhttp/util/StringUtil.cpp \
	../../src/uhttp/util/Thread.cpp \
	../../src/uhttp/util/ThreadList.cpp \
	../../src/uhttp/util/TimeUtil.cpp

libuhttp___a_SOURCES = \
        $(uhttpcc_sources)
