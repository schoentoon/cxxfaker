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

TEST_F(Base, RandomVectorElement) {
  cxxfaker::providers::Base* base = new cxxfaker::providers::Base();
  base->Seed(::testing::UnitTest::GetInstance()->random_seed());
  std::vector<int> v;
  for (int i = 0; i < 1000; ++i)
    v.push_back(i);
  std::vector<int>::const_iterator iter = base->randomElement<int>(v);
  EXPECT_GE(iter, v.begin());
  EXPECT_LE(iter, v.end());
  delete base;
};

TEST_F(Base, RandomSetElement) {
  cxxfaker::providers::Base* base = new cxxfaker::providers::Base();
  base->Seed(::testing::UnitTest::GetInstance()->random_seed());
  std::set<int> s;
  for (int i = 0; i < 1000; ++i)
    s.insert(i);
  std::set<int>::const_iterator iter = base->randomElement<int>(s);
  std::set<int>::const_iterator found = s.find(*iter);
  EXPECT_NE(found, s.end());
  delete base;
};

TEST_F(Base, RandomMapElement) {
  cxxfaker::providers::Base* base = new cxxfaker::providers::Base();
  base->Seed(::testing::UnitTest::GetInstance()->random_seed());
  std::map<int, int> m;
  for (int i = 0; i < 1000; ++i)
    m[i] = i * 1000;
  std::map<int, int>::const_iterator iter = base->randomElement<int, int>(m);
  std::map<int, int>::const_iterator found = m.find(iter->first);
  EXPECT_NE(found, m.end());
  delete base;
};

};