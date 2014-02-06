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

#include "DateTime.h"

#include "Base_test.h"

using namespace cxxfaker::providers;

namespace tests {

class DateTime : public ::tests::Base {
};

TEST_F(DateTime, Between) {
  cxxfaker::providers::DateTime* datetime = new cxxfaker::providers::DateTime();
  datetime->Seed(::testing::UnitTest::GetInstance()->random_seed());
  ASSERT_FALSE(datetime->isInitialized());
  EXPECT_TRUE(datetime->initBetween(0, 3600));
  ASSERT_TRUE(datetime->isInitialized());
  EXPECT_GE(datetime->unixTime(), 0);
  EXPECT_LE(datetime->unixTime(), 3600);
  delete datetime;
};

TEST_F(DateTime, ThisYear) {
  cxxfaker::providers::DateTime* datetime = new cxxfaker::providers::DateTime();
  datetime->Seed(::testing::UnitTest::GetInstance()->random_seed());
  ASSERT_FALSE(datetime->isInitialized());
  EXPECT_TRUE(datetime->initThisYear());
  ASSERT_TRUE(datetime->isInitialized());
  EXPECT_FALSE(datetime->initThisYear());

  std::time_t now = time(NULL);
  struct tm *time = std::localtime(&now);
  const int year = 1900 + time->tm_year;
  if (!(datetime->getYear() == year || datetime->getYear() == (year - 1))) {
    ADD_FAILURE() << "Expected year " << year << " or " << (year - 1) << " but got year " << datetime->getYear();
  };
  delete datetime;
};

TEST_F(DateTime, ThisMonth) {
  cxxfaker::providers::DateTime* datetime = new cxxfaker::providers::DateTime();
  datetime->Seed(::testing::UnitTest::GetInstance()->random_seed());
  ASSERT_FALSE(datetime->isInitialized());
  EXPECT_TRUE(datetime->initThisMonth());
  ASSERT_TRUE(datetime->isInitialized());
  EXPECT_FALSE(datetime->initThisMonth());

  std::time_t now = time(NULL);
  struct tm *time = std::localtime(&now);
  const int month = time->tm_mon;
  if (!(datetime->getMonth() == month || datetime->getMonth() == (month - 1))) {
    ADD_FAILURE() << "Expected month " << month << " or " << (month - 1) << " but got month " << datetime->getMonth();
  };
  delete datetime;
};

TEST_F(DateTime, Now) {
  cxxfaker::providers::DateTime* datetime = new cxxfaker::providers::DateTime();
  datetime->Seed(::testing::UnitTest::GetInstance()->random_seed());
  ASSERT_FALSE(datetime->isInitialized());
  EXPECT_TRUE(datetime->initNow());
  ASSERT_TRUE(datetime->isInitialized());
  EXPECT_FALSE(datetime->initNow());
  delete datetime;
};

TEST_F(DateTime, Format) {
  cxxfaker::providers::DateTime* datetime = new cxxfaker::providers::DateTime();
  datetime->Seed(::testing::UnitTest::GetInstance()->random_seed());
  ASSERT_FALSE(datetime->isInitialized());
  EXPECT_TRUE(datetime->initBetween(0, 3600));
  ASSERT_TRUE(datetime->isInitialized());
  EXPECT_GE(datetime->unixTime(), 0);
  EXPECT_LE(datetime->unixTime(), 3600);
  STRING str = datetime->format("%Y:%m:%d");
  EXPECT_EQ("1970:01:01", str);
  try {
    str = datetime->format("%A %B", std::locale("ja_JP.utf8"));
    EXPECT_EQ("木曜日 1月", str);
  } catch (std::runtime_error) {
    // We don't have this locale, doesn't mind we just don't test with it then..
  };
  delete datetime;
};

};