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
      char randomLetter() const;
      template<typename T>
      typename std::vector<T>::iterator randomElement(std::vector<T> &v) const {
        typename std::vector<T>::iterator iter = v.begin();
        int number = randomInt(0, v.size());
        for (int i = 0; i < number; ++i)
          ++iter;
        return iter;
      };
      template<typename T>
      typename std::set<T>::iterator randomElement(std::set<T> &s) const {
        typename std::set<T>::iterator iter = s.begin();
        int number = randomInt(0, s.size());
        for (int i = 0; i < number; ++i)
          ++iter;
        return iter;
      };
      template<typename K, typename V>
      typename std::map<K, V>::iterator randomElement(std::map<K, V> &m) const {
        typename std::map<K, V>::iterator iter = m.begin();
        int number = randomInt(0, m.size());
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