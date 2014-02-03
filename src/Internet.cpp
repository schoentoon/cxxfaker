#include "Internet.h"

#include <cstdlib>
#include <sstream>
#include <iomanip>

using namespace cxxfaker::providers;

STRING Internet::IPv4() {
  std::stringstream output;
  for (int i = 0; i < 4; i++) {
    output << randomInt(0, 256);
    if (i != 3)
      output << ".";
  };
  return output.str();
};

STRING Internet::IPv6() {
  std::stringstream output;
  output << std::hex
         << std::setw(4)
         << std::setfill('0');
  for (int i = 0; i < 8; i++) {
    output << randomInt(0, 65535);
    if (i != 7)
      output << ":";
  };
  return output.str();
};