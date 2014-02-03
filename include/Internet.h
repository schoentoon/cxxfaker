#ifndef _INTERNET_H
#define _INTERNET_H

#include "defines.h"

#include "Base.h"

namespace cxxfaker {
  namespace providers {
    class Internet : public Base {
    public:
      Internet(randGenerator* generator = NULL, randSeeder* seeder = NULL)
      : Base(generator, seeder) {
      };
      STRING IPv4();
      STRING IPv6();
    };
  };
};

#endif //_INTERNET_H