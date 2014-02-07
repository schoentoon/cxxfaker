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

#include "locale/ro_MD/PhoneNumber.h"

#include <iostream>

namespace cxxfaker {
  namespace providers {
    namespace ro_MD {

PhoneNumber::PhoneNumber(randGenerator* generator, randSeeder* seeder)
: cxxfaker::providers::PhoneNumber(generator, seeder) {
  formats.clear(); // We don't want the default one..
  formats.push_back("a## # ## ##");
  formats.push_back("(022) ### ###");
  formats.push_back("+373 60 ### ###");
  formats.push_back("+373 65 0## ###");
  formats.push_back("+373 67 ### ###");
  formats.push_back("+373 68 ### ###");
  formats.push_back("+373 69 ### ###");
  formats.push_back("+373 78 ### ###");
  formats.push_back("+373 79 ### ###");
  formats.push_back("+373 77 4## ###");
  formats.push_back("+373 77 7## ###");
  formats.push_back("+373 77 8## ###");
  formats.push_back("+373 77 9## ###");
  formats.push_back("(373) 60 ### ###");
  formats.push_back("(373) 65 0## ###");
  formats.push_back("(373) 67 ### ###");
  formats.push_back("(373) 68 ### ###");
  formats.push_back("(373) 69 ### ###");
  formats.push_back("(373) 78 ### ###");
  formats.push_back("(373) 79 ### ###");
  formats.push_back("(373) 77 4## ###");
  formats.push_back("(373) 77 7## ###");
  formats.push_back("(373) 77 8## ###");
  formats.push_back("(373) 77 9## ###");
};

    };
  };
};