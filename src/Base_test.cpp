/*  tripping-cyril
 *  Copyright (C) 2014  Toon Schoenmakers
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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

TEST_F(Base, RandomLowerLetter) {
  cxxfaker::providers::Base* base = new cxxfaker::providers::Base();
  char letter = base->randomLowerLetter();
  EXPECT_TRUE(isalpha(letter));
  EXPECT_TRUE(islower(letter));
  delete base;
};

TEST_F(Base, RandomUpperLetter) {
  cxxfaker::providers::Base* base = new cxxfaker::providers::Base();
  char letter = base->randomUpperLetter();
  EXPECT_TRUE(isalpha(letter));
  EXPECT_TRUE(isupper(letter));
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

TEST_F(Base, FillString) {
  cxxfaker::providers::Base* base = new cxxfaker::providers::Base();
  base->Seed(::testing::UnitTest::GetInstance()->random_seed());
  const char buf[] = { -0x01, -0x02, -0x03, -0x04, '1', '3', '3', '7' };
  std::string input(buf, sizeof(buf));
  int mod = base->fillString(input);
  EXPECT_EQ(mod, 4);
  EXPECT_TRUE(isdigit(input[0]));
  EXPECT_TRUE(isdigit(input[1]));
  EXPECT_NE('0', input[1]);
  EXPECT_TRUE(islower(input[2]));
  EXPECT_TRUE(isupper(input[3]));
  EXPECT_EQ('1', input[4]);
  EXPECT_EQ('3', input[5]);
  EXPECT_EQ('3', input[6]);
  EXPECT_EQ('7', input[7]);
  delete base;
};

};