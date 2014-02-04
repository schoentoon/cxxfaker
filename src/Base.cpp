#include "Base.h"

using namespace cxxfaker::providers;

Base::Base(randGenerator* pGenerator, randSeeder* pSeeder) {
  generator = pGenerator;
  seeder = pSeeder;
  if (seeder == NULL)
    seeder = std::srand;
  if (generator == NULL)
    generator = std::rand;
};

Base::~Base() {
};

void Base::Seed(unsigned int seed) {
  seeder(seed);
};

int Base::randomInt(int min, int max) const {
  return generator() % ((max + 1) - min) + min;
};

char Base::randomLetter() const {
  return randomInt('a', 'z');
};