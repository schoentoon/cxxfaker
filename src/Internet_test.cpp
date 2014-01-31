#include <gtest/gtest.h>

#include "Internet.h"

#include <iostream>

#include <arpa/inet.h>

using namespace cxxfaker::providers;

namespace tests {

class Internet : public ::testing::Test {
public:
  static int fakeGenerator() { return _number; };
  static int _number;
};

int Internet::_number = 0;

TEST_F(Internet, IPv4) {
  STRING ipv4 = cxxfaker::providers::Internet::IPv4();
  struct in_addr addr;
  EXPECT_EQ(1, inet_pton(AF_INET, ipv4.c_str(), &addr));
};

TEST_F(Internet, IPv4CustomRandomizer) {
  _number = 266; // Becomes 10
  STRING ipv4 = cxxfaker::providers::Internet::IPv4(fakeGenerator);
  EXPECT_EQ(ipv4, "10.10.10.10");
  struct in_addr addr;
  EXPECT_EQ(1, inet_pton(AF_INET, ipv4.c_str(), &addr));
};

TEST_F(Internet, IPv6) {
  STRING ipv6 = cxxfaker::providers::Internet::IPv6();
  struct in6_addr addr;
  EXPECT_EQ(1, inet_pton(AF_INET6, ipv6.c_str(), &addr));
};

TEST_F(Internet, IPv6CustomRandomizer) {
  _number = 32423; // Becomes 7ea7
  STRING ipv6 = cxxfaker::providers::Internet::IPv6(fakeGenerator);
  EXPECT_EQ(ipv6, "7ea7:7ea7:7ea7:7ea7:7ea7:7ea7:7ea7:7ea7");
  struct in6_addr addr;
  EXPECT_EQ(1, inet_pton(AF_INET6, ipv6.c_str(), &addr));
};

};