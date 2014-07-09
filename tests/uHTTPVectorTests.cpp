/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <string>
#include <vector>

#include <boost/test/unit_test.hpp>
#include <uhttp/util/Vector.h>

using namespace uHTTP;

class TestVectorObject {
public:
  TestVectorObject() {
  }
};

class TestVectorList : public Vector<TestVectorObject>  {
public:
  TestVectorList() {
  }
};

BOOST_AUTO_TEST_CASE(VectorTests)
{
  const size_t TEST_VECTOR_OBJECT_NUM = 10;
  
  TestVectorList vectorObjectList;
	BOOST_CHECK_EQUAL(vectorObjectList.size(), 0);

  TestVectorObject *vectorObject[TEST_VECTOR_OBJECT_NUM];
  for (size_t n=0; n<TEST_VECTOR_OBJECT_NUM; n++) {
    vectorObject[n] = new TestVectorObject();
  }

  for (size_t n=0; n<TEST_VECTOR_OBJECT_NUM; n++) {
    BOOST_CHECK_EQUAL(vectorObjectList.size(), n);
    vectorObjectList.add(vectorObject[n]);
    BOOST_CHECK_EQUAL(vectorObjectList.size(), (n+1));
  }

  for (size_t n=0; n<TEST_VECTOR_OBJECT_NUM; n++) {
    BOOST_CHECK_EQUAL(vectorObjectList.size(), (TEST_VECTOR_OBJECT_NUM - n));
    vectorObjectList.remove(vectorObject[n]);
    BOOST_CHECK_EQUAL(vectorObjectList.size(), (TEST_VECTOR_OBJECT_NUM - (n+1)));
  }

  for (size_t n=0; n<TEST_VECTOR_OBJECT_NUM; n++) {
    delete vectorObject[n];
  }
  
	BOOST_CHECK_EQUAL(vectorObjectList.size(), 0);
}
