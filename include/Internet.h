#ifndef _INTERNET_H
#define _INTERNET_H

#include "defines.h"

typedef int randGenerator();
typedef void randSeeder(unsigned int seed);

namespace cxxfaker {
  namespace providers {
    class Internet {
    public:
      static STRING IPv4(randGenerator* random = NULL, randSeeder* seeder = NULL, unsigned int seed = 0);
      static STRING IPv6(randGenerator* random = NULL, randSeeder* seeder = NULL, unsigned int seed = 0);
    };
  };
};

#endif //_INTERNET_H