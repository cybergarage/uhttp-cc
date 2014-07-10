############################################################
#
# uHTTP for C++
#
# Copyright (C) Satoshi Konno 2002
#
############################################################

noinst_PROGRAMS = uhttpcctestunit

AM_CPPFLAGS = -I$(top_srcdir)/include -I../

uhttpcctestunit_SOURCES = \
	../uHTTPSocketTests.cpp \
	../uHTTPServerTests.cpp \
	../uHTTDateTests.cpp \
	../uHTTPMutexTests.cpp \
	../uHTTPUriTests.cpp \
	../uHTTPThreadTests.cpp \
	../uHTTPLoggerTests.cpp \
	../uHTTPTestMain.cpp \
	../uHTTPRequestTests.cpp \
	../uHTTPPacketTests.cpp \
	../uHTTPRandomTests.cpp \
	../uHTTPNetworkInterfaceTests.cpp \
	../uHTTPStringTests.cpp \
	../uHTTPGetTests.cpp \
	../uHTTPVectorTests.cpp

uhttpcctestunit_LDADD = ../../lib/unix/libuhttp++.a
