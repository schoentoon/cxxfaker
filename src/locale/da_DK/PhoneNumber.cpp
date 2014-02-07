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

#include "locale/da_DK/PhoneNumber.h"

#include <iostream>

namespace cxxfaker {
  namespace providers {
    namespace da_DK {

PhoneNumber::PhoneNumber(randGenerator* generator, randSeeder* seeder)
: cxxfaker::providers::PhoneNumber(generator, seeder) {
  formats.clear(); // We don't want the default one..
  formats.push_back("+45 ## ## ## ##");
  formats.push_back("+45 #### ####");
  formats.push_back("+45########");
  formats.push_back("## ## ## ##");
  formats.push_back("#### ####");
  formats.push_back("########");
};

    };
  };
};