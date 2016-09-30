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
	../VectorTests.cpp \
	../LoggerTests.cpp \
	../HTTPTestMain.cpp \
	../RandomTests.cpp \
	../StringTests.cpp \
	../HTTPServerTests.cpp \
	../NetworkInterfaceTests.cpp \
	../MutexTests.cpp \
	../SemaphoreTests.cpp \
	../UriTests.cpp \
	../SocketTests.cpp \
	../DateTests.cpp \
	../ThreadTests.cpp \
	../ParameterTests.cpp \
	../HTTPStatusTests.cpp \
	../HTTPPacketTests.cpp \
	../HTTPRequestTests.cpp \
	../HTTPClientTests.cpp \
	../MessageQueue.cpp

uhttpcctest_LDADD = ../../lib/unix/libuhttp++.a
