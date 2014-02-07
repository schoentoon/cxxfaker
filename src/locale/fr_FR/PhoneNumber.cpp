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

#include "locale/fr_FR/PhoneNumber.h"

#include <iostream>

namespace cxxfaker {
  namespace providers {
    namespace fr_FR {

PhoneNumber::PhoneNumber(randGenerator* generator, randSeeder* seeder)
: cxxfaker::providers::PhoneNumber(generator, seeder) {
  formats.clear(); // We don't want the default one..
  formats.push_back("+33 (0)1 ## ## ## ##");
  formats.push_back("+33 (0)1 ## ## ## ##");
  formats.push_back("+33 (0)2 ## ## ## ##");
  formats.push_back("+33 (0)3 ## ## ## ##");
  formats.push_back("+33 (0)4 ## ## ## ##");
  formats.push_back("+33 (0)5 ## ## ## ##");
  formats.push_back("+33 (0)6 ## ## ## ##");
  formats.push_back("+33 (0)7 ## ## ## ##");
  formats.push_back("+33 (0)8 ## ## ## ##");
  formats.push_back("+33 (0)9 ## ## ## ##");
  formats.push_back("+33 1 ## ## ## ##");
  formats.push_back("+33 1 ## ## ## ##");
  formats.push_back("+33 2 ## ## ## ##");
  formats.push_back("+33 3 ## ## ## ##");
  formats.push_back("+33 4 ## ## ## ##");
  formats.push_back("+33 5 ## ## ## ##");
  formats.push_back("+33 6 ## ## ## ##");
  formats.push_back("+33 7 ## ## ## ##");
  formats.push_back("+33 8 ## ## ## ##");
  formats.push_back("+33 9 ## ## ## ##");
  formats.push_back("01########");
  formats.push_back("01########");
  formats.push_back("02########");
  formats.push_back("03########");
  formats.push_back("04########");
  formats.push_back("05########");
  formats.push_back("06########");
  formats.push_back("07########");
  formats.push_back("08########");
  formats.push_back("09########");
  formats.push_back("01 ## ## ## ##");
  formats.push_back("01 ## ## ## ##");
  formats.push_back("02 ## ## ## ##");
  formats.push_back("03 ## ## ## ##");
  formats.push_back("04 ## ## ## ##");
  formats.push_back("05 ## ## ## ##");
  formats.push_back("06 ## ## ## ##");
  formats.push_back("07 ## ## ## ##");
  formats.push_back("08 ## ## ## ##");
  formats.push_back("09 ## ## ## ##");
};

    };
  };
};