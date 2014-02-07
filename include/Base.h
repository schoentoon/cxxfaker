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

#ifndef _BASE_H
#define _BASE_H

#include <cstdlib>
#include <vector>
#include <set>
#include <map>

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
      int randomInt(int min = 0, int max = RAND_MAX) const;
      char randomLowerLetter() const;
      char randomUpperLetter() const;
      int fillString(STRING &str) const;
      int numerify(STRING& str, bool withZero = true) const;
      template<typename T>
      typename std::vector<T>::const_iterator randomElement(std::vector<T> &v) const {
        typename std::vector<T>::iterator iter = v.begin();
        int number = randomInt(0, v.size() - 1);
        for (int i = 0; i < number; ++i)
          ++iter;
        return iter;
      };
      template<typename T>
      typename std::set<T>::const_iterator randomElement(std::set<T> &s) const {
        typename std::set<T>::iterator iter = s.begin();
        int number = randomInt(0, s.size() - 1);
        for (int i = 0; i < number; ++i)
          ++iter;
        return iter;
      };
      template<typename K, typename V>
      typename std::map<K, V>::const_iterator randomElement(std::map<K, V> &m) const {
        typename std::map<K, V>::iterator iter = m.begin();
        int number = randomInt(0, m.size() - 1);
        for (int i = 0; i < number; ++i)
          ++iter;
        return iter;
      };
    private:
      randGenerator* generator;
      randSeeder* seeder;
    };
  };
};

#endif //_BASE_H