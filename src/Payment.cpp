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

#include "Payment.h"

using namespace cxxfaker::providers;

Payment::Payment(randGenerator* generator, randSeeder* seeder)
: Base(generator, seeder) {
  cardVendors.push_back("Visa"); // Visa and Mastercard are more common, therefore
  cardVendors.push_back("Visa"); // we give them a higher chance
  cardVendors.push_back("Visa");
  cardVendors.push_back("Visa");
  cardVendors.push_back("Visa");
  cardVendors.push_back("MasterCard");
  cardVendors.push_back("MasterCard");
  cardVendors.push_back("MasterCard");
  cardVendors.push_back("MasterCard");
  cardVendors.push_back("MasterCard");
  cardVendors.push_back("American Express");
  cardVendors.push_back("Discover Card");

  cardParams["Visa"].push_back("4539#########");
  cardParams["Visa"].push_back("4539############");
  cardParams["Visa"].push_back("4556#########");
  cardParams["Visa"].push_back("4556############");
  cardParams["Visa"].push_back("4916#########");
  cardParams["Visa"].push_back("4916############");
  cardParams["Visa"].push_back("4532#########");
  cardParams["Visa"].push_back("4532############");
  cardParams["Visa"].push_back("4929#########");
  cardParams["Visa"].push_back("4929############");
  cardParams["Visa"].push_back("40240071#####");
  cardParams["Visa"].push_back("40240071########");
  cardParams["Visa"].push_back("4485#########");
  cardParams["Visa"].push_back("4485############");
  cardParams["Visa"].push_back("4716#########");
  cardParams["Visa"].push_back("4716############");
  cardParams["Visa"].push_back("4############");
  cardParams["Visa"].push_back("4###############");
  cardParams["MasterCard"].push_back("51##############");
  cardParams["MasterCard"].push_back("52##############");
  cardParams["MasterCard"].push_back("53##############");
  cardParams["MasterCard"].push_back("54##############");
  cardParams["MasterCard"].push_back("55##############");
  cardParams["American Express"].push_back("34#############");
  cardParams["American Express"].push_back("37#############");
  cardParams["Discover Card"].push_back("6011############");
};

STRING Payment::creditCardType() {
  std::vector<STRING>::const_iterator iter = randomElement<STRING>(cardVendors);
  return *iter;
};

STRING Payment::creditCardNumber(const STRING& type, bool formatted, char separator) {
  std::map<STRING, std::vector<STRING> >::iterator iter = cardParams.find(type);
  if (iter == cardParams.end())
    iter = cardParams.find(creditCardType());
  std::vector<STRING>::const_iterator mask_iter = randomElement<STRING>(iter->second);
  STRING number(*mask_iter);
  numerify(number);
  if (formatted) {
    STRING output(number.substr(0, 4));
    output += separator;
    output += number.substr(4, 4);
    output += separator;
    output += number.substr(8, 4);
    output += separator;
    output += number.substr(12);
    return output;
  };
  return number;
};