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

#include "Internet.h"

#include "Base_test.h"

#include <arpa/inet.h>

using namespace cxxfaker::providers;

namespace tests {

class Internet : public ::tests::Base {
};

TEST_F(Internet, IPv4) {
  cxxfaker::providers::Internet* internet = new cxxfaker::providers::Internet();
  internet->Seed(::testing::UnitTest::GetInstance()->random_seed());
  STRING ipv4 = internet->IPv4();
  struct in_addr addr;
  EXPECT_EQ(1, inet_pton(AF_INET, ipv4.c_str(), &addr));
  delete internet;
};

TEST_F(Internet, IPv4CustomRandomizer) {
  _number = 266; // Becomes 10
  cxxfaker::providers::Internet* internet = new cxxfaker::providers::Internet(fakeGenerator);
  internet->Seed(::testing::UnitTest::GetInstance()->random_seed());
  STRING ipv4 = internet->IPv4();
  EXPECT_EQ(ipv4, "10.10.10.10");
  struct in_addr addr;
  EXPECT_EQ(1, inet_pton(AF_INET, ipv4.c_str(), &addr));
  delete internet;
};

TEST_F(Internet, IPv6) {
  cxxfaker::providers::Internet* internet = new cxxfaker::providers::Internet();
  internet->Seed(::testing::UnitTest::GetInstance()->random_seed());
  STRING ipv6 = internet->IPv6();
  struct in6_addr addr;
  EXPECT_EQ(1, inet_pton(AF_INET6, ipv6.c_str(), &addr));
  delete internet;
};

TEST_F(Internet, IPv6CustomRandomizer) {
  _number = 32423; // Becomes 7ea7
  cxxfaker::providers::Internet* internet = new cxxfaker::providers::Internet(fakeGenerator);
  internet->Seed(::testing::UnitTest::GetInstance()->random_seed());
  STRING ipv6 = internet->IPv6();
  EXPECT_EQ(ipv6, "7ea7:7ea7:7ea7:7ea7:7ea7:7ea7:7ea7:7ea7");
  struct in6_addr addr;
  EXPECT_EQ(1, inet_pton(AF_INET6, ipv6.c_str(), &addr));
  delete internet;
};

};