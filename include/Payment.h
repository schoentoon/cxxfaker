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

#ifndef _PAYMENT_H
#define _PAYMENT_H

#include "defines.h"

#include "Base.h"

namespace cxxfaker {
  namespace providers {
    class Payment : public Base {
    public:
      Payment(randGenerator* generator = NULL, randSeeder* seeder = NULL);
      virtual ~Payment() {};
      STRING creditCardType();
      STRING creditCardNumber(const STRING& type = "", bool formatted = false, char separator = '-');
    protected:
      std::vector<STRING> cardVendors;
      std::map<STRING, std::vector<STRING> > cardParams;
    };
  };
};

#endif //_PAYMENT_H