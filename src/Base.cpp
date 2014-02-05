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

char Base::randomLowerLetter() const {
  return randomInt('a', 'z');
};

char Base::randomUpperLetter() const {
  return randomInt('A', 'Z');
};