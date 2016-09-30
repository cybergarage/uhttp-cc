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
	..//DateTests.cpp \
	..//HTTPClientTests.cpp \
	..//HTTPPacketTests.cpp \
	..//HTTPRequestTests.cpp \
	..//HTTPServerTests.cpp \
	..//HTTPStatusTests.cpp \
	..//HTTPTestMain.cpp \
	..//LoggerTests.cpp \
	..//MessageQueue.cpp \
	..//MutexTests.cpp \
	..//NetworkInterfaceTests.cpp \
	..//ParameterTests.cpp \
	..//RandomTests.cpp \
	..//SemaphoreTests.cpp \
	..//SocketTests.cpp \
	..//StringTests.cpp \
	..//ThreadTests.cpp \
	..//UriTests.cpp \
	..//VectorTests.cpp

uhttpcctest_LDADD = ../../lib/unix/libuhttp++.a
