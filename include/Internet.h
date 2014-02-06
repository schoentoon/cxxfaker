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

#ifndef _INTERNET_H
#define _INTERNET_H

#include "defines.h"

#include "Base.h"

namespace cxxfaker {
  namespace providers {
    class Internet : public Base {
    public:
      Internet(randGenerator* generator = NULL, randSeeder* seeder = NULL)
      : Base(generator, seeder) {
      };
      virtual ~Internet() {};
      STRING IPv4();
      STRING IPv6();
    };
  };
};

#endif //_INTERNET_H