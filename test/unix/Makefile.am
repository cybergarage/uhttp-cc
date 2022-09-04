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
	../LoggerTests.cpp \
	../HTTPTestMain.cpp \
	../DateTests.cpp \
	../ThreadTests.cpp \
	../HTTPPacketTests.cpp \
	../StringTests.cpp \
	../HTTPClientTests.cpp \
	../MessageQueue.cpp \
	../VectorTests.cpp \
	../SocketTests.cpp \
	../ParameterTests.cpp \
	../RandomTests.cpp \
	../MutexTests.cpp \
	../SemaphoreTests.cpp \
	../HTTPRequestTests.cpp \
	../HTTPStatusTests.cpp \
	../NetworkInterfaceTests.cpp \
	../HTTPServerTests.cpp \
	../UriTests.cpp

uhttpcctest_LDADD = ../../lib/unix/libuhttp++.a
