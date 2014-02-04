#ifndef _BASE_TEST_H
#define _BASE_TEST_H

#include <gtest/gtest.h>

namespace tests {

class Base : public ::testing::Test {
public:
  static int fakeGenerator() { return _number; };
  static int _number;
};

};

#endif //_BASE_TEST_H