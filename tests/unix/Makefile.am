noinst_PROGRAMS = uhttpcctestunit

AM_CPPFLAGS = -I$(top_srcdir)/include -I../

uhttpcctestunit_SOURCES = \
	../uHTTDateTests.cpp \
	../uHTTPGetTests.cpp \
	../uHTTPMutexTests.cpp \
	../uHTTPNetworkInterfaceTests.cpp \
	../uHTTPPacketTests.cpp \
	../uHTTPRandomTests.cpp \
	../uHTTPRequestTests.cpp \
	../uHTTPServerTests.cpp \
	../uHTTPSocketTests.cpp \
	../uHTTPStringTests.cpp \
	../uHTTPTestMain.cpp \
	../uHTTPLoggerTests.cpp \
	../uHTTPUriTests.cpp

uhttpcctestunit_LDADD = ../../lib/unix/libuhttp++.a
