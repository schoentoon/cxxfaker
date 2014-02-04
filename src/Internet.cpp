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

#include "Internet.h"

#include <cstdlib>
#include <sstream>
#include <iomanip>

using namespace cxxfaker::providers;

STRING Internet::IPv4() {
  std::stringstream output;
  for (int i = 0; i < 4; i++) {
    output << randomInt(0, 255);
    if (i != 3)
      output << ".";
  };
  return output.str();
};

STRING Internet::IPv6() {
  std::stringstream output;
  output << std::hex
         << std::setw(4)
         << std::setfill('0');
  for (int i = 0; i < 8; i++) {
    output << randomInt(0, 65534);
    if (i != 7)
      output << ":";
  };
  return output.str();
};