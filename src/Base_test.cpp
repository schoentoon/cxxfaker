#include <gtest/gtest.h>

#include "Base.h"

namespace tests {

class Base : public ::testing::Test {
public:
  static int fakeGenerator() { return _number; };
  static int _number;
};

int Base::_number = 0;

TEST_F(Base, RandomInt) {
  cxxfaker::providers::Base* base = new cxxfaker::providers::Base();
  base->Seed(::testing::UnitTest::GetInstance()->random_seed());
  int number = base->randomInt(0, 10);
  EXPECT_GE(number, 0);
  EXPECT_LE(number, 10);
  delete base;
};

TEST_F(Base, RandomLetter) {
  cxxfaker::providers::Base* base = new cxxfaker::providers::Base();
  char letter = base->randomLetter();
  EXPECT_TRUE(isalpha(letter));
  delete base;
};

TEST_F(Base, FakeGenerator) {
  _number = 10;
  cxxfaker::providers::Base* base = new cxxfaker::providers::Base(fakeGenerator);
  base->Seed(::testing::UnitTest::GetInstance()->random_seed());
  int number = base->randomInt(0, 10);
  EXPECT_EQ(number, 10);
  _number = 1337;
  number = base->randomInt(0, 9001);
  EXPECT_EQ(number, 1337);
  delete base;
};

};