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

  BOOST_CHECK_EQUAL(vectorObjectList.add(NULL), false);
  BOOST_CHECK_EQUAL(vectorObjectList.remove(NULL), false);
  BOOST_CHECK_EQUAL(vectorObjectList.insertAt(NULL, 0), false);
  BOOST_CHECK_EQUAL(vectorObjectList.indexOf(NULL), -1);
  
  TestVectorObject *vectorObject[TEST_VECTOR_OBJECT_NUM];
  for (size_t n=0; n<TEST_VECTOR_OBJECT_NUM; n++) {
    vectorObject[n] = new TestVectorObject();
  }

  for (size_t n=0; n<TEST_VECTOR_OBJECT_NUM; n++) {
    BOOST_CHECK_EQUAL(vectorObjectList.size(), n);
    BOOST_CHECK_EQUAL(vectorObjectList.indexOf(vectorObject[n]), -1);
    vectorObjectList.add(vectorObject[n]);
    BOOST_CHECK_EQUAL(vectorObjectList.size(), (n+1));
    BOOST_CHECK_EQUAL(vectorObjectList.indexOf(vectorObject[n]), n);
  }

  for (size_t n=0; n<TEST_VECTOR_OBJECT_NUM; n++) {
    BOOST_CHECK_EQUAL(vectorObjectList.size(), (TEST_VECTOR_OBJECT_NUM - n));
    BOOST_CHECK_EQUAL(vectorObjectList.indexOf(vectorObject[n]), 0);
    vectorObjectList.remove(vectorObject[n]);
    BOOST_CHECK_EQUAL(vectorObjectList.size(), (TEST_VECTOR_OBJECT_NUM - (n+1)));
    BOOST_CHECK_EQUAL(vectorObjectList.indexOf(vectorObject[n]), -1);
  }

  BOOST_CHECK_EQUAL(vectorObjectList.size(), 0);
}
