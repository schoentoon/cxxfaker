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

#ifndef _RO_MD_PHONENUMBER_H
#define _RO_MD_PHONENUMBER_H

#include "defines.h"

#include "../../PhoneNumber.h"

namespace cxxfaker {
  namespace providers {
    namespace ro_MD {
      class PhoneNumber : public cxxfaker::providers::PhoneNumber {
      public:
        PhoneNumber(randGenerator* generator = NULL, randSeeder* seeder = NULL);
        virtual ~PhoneNumber() {};
      };
    };
  };
};

#endif //_RO_MD_PHONENUMBER_H