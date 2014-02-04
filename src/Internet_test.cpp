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
  STRING ipv4 = internet->IPv4();
  struct in_addr addr;
  EXPECT_EQ(1, inet_pton(AF_INET, ipv4.c_str(), &addr));
  delete internet;
};

TEST_F(Internet, IPv4CustomRandomizer) {
  _number = 266; // Becomes 10
  cxxfaker::providers::Internet* internet = new cxxfaker::providers::Internet(fakeGenerator);
  STRING ipv4 = internet->IPv4();
  EXPECT_EQ(ipv4, "10.10.10.10");
  struct in_addr addr;
  EXPECT_EQ(1, inet_pton(AF_INET, ipv4.c_str(), &addr));
  delete internet;
};

TEST_F(Internet, IPv6) {
  cxxfaker::providers::Internet* internet = new cxxfaker::providers::Internet();
  STRING ipv6 = internet->IPv6();
  struct in6_addr addr;
  EXPECT_EQ(1, inet_pton(AF_INET6, ipv6.c_str(), &addr));
  delete internet;
};

TEST_F(Internet, IPv6CustomRandomizer) {
  _number = 32423; // Becomes 7ea7
  cxxfaker::providers::Internet* internet = new cxxfaker::providers::Internet(fakeGenerator);
  STRING ipv6 = internet->IPv6();
  EXPECT_EQ(ipv6, "7ea7:7ea7:7ea7:7ea7:7ea7:7ea7:7ea7:7ea7");
  struct in6_addr addr;
  EXPECT_EQ(1, inet_pton(AF_INET6, ipv6.c_str(), &addr));
  delete internet;
};

};