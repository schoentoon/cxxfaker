#ifndef _BASE_H
#define _BASE_H

#include <cstdlib>

#include "defines.h"

typedef int randGenerator();
typedef void randSeeder(unsigned int seed);

namespace cxxfaker {
  namespace providers {
    class Base {
    public:
      Base(randGenerator* generator = NULL, randSeeder* seeder = NULL);
      virtual ~Base();
      void Seed(unsigned int seed);
      int randomInt(int min = 0, int max = RAND_MAX);
    private:
      randGenerator* generator;
      randSeeder* seeder;
    };
  };
};

#endif //_BASE_H