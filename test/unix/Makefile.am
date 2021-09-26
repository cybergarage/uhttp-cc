############################################################
#
# uHTTP for C++
#
# Copyright (C) Satoshi Konno 2002
#
############################################################

TESTS = uhttpcctest
noinst_PROGRAMS = uhttpcctest

AM_CPPFLAGS = -I$(top_srcdir)/include -I../

uhttpcctest_SOURCES = \
	../SemaphoreTests.cpp \
	../HTTPRequestTests.cpp \
	../StringTests.cpp \
	../VectorTests.cpp \
	../HTTPServerTests.cpp \
	../HTTPTestMain.cpp \
	../HTTPPacketTests.cpp \
	../NetworkInterfaceTests.cpp \
	../ThreadTests.cpp \
	../HTTPStatusTests.cpp \
	../ParameterTests.cpp \
	../DateTests.cpp \
	../UriTests.cpp \
	../MutexTests.cpp \
	../MessageQueue.cpp \
	../RandomTests.cpp \
	../LoggerTests.cpp \
	../HTTPClientTests.cpp \
	../SocketTests.cpp

uhttpcctest_LDADD = ../../lib/unix/libuhttp++.a
