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

#include "locale/hy_AM/PhoneNumber.h"

#include <iostream>

namespace cxxfaker {
  namespace providers {
    namespace hy_AM {

PhoneNumber::PhoneNumber(randGenerator* generator, randSeeder* seeder)
: cxxfaker::providers::PhoneNumber(generator, seeder) {
  formats.clear(); // We don't want the default one..
  formats.push_back("093 ######");
  formats.push_back("093 ##-##-##");
  formats.push_back("(093) ######");
  formats.push_back("(093) ##-##-##");
  formats.push_back("094 ######");
  formats.push_back("094 ##-##-##");
  formats.push_back("(094) ######");
  formats.push_back("(094) ##-##-##");
  formats.push_back("095 ######");
  formats.push_back("095 ##-##-##");
  formats.push_back("(095) ######");
  formats.push_back("(095) ##-##-##");
  formats.push_back("096 ######");
  formats.push_back("096 ##-##-##");
  formats.push_back("(096) ######");
  formats.push_back("(096) ##-##-##");
  formats.push_back("099 ######");
  formats.push_back("099 ##-##-##");
  formats.push_back("(099) ######");
  formats.push_back("(099) ##-##-##");
  formats.push_back("077 ######");
  formats.push_back("077 ##-##-##");
  formats.push_back("(077) ######");
  formats.push_back("(077) ##-##-##");
  formats.push_back("055 ######");
  formats.push_back("055 ##-##-##");
  formats.push_back("(055) ######");
  formats.push_back("(055) ##-##-##");
};

    };
  };
};