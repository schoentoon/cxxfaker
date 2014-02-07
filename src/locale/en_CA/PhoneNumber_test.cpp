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

#include <gtest/gtest.h>

#include "locale/en_CA/PhoneNumber.h"

#include "Base_test.h"

using namespace cxxfaker::providers;

namespace tests {

class en_CA_PhoneNumber : public ::tests::Base {
};

TEST_F(en_CA_PhoneNumber, PhoneNumber) {
  cxxfaker::providers::en_CA::PhoneNumber* phonenumber = new cxxfaker::providers::en_CA::PhoneNumber();
  phonenumber->Seed(::testing::UnitTest::GetInstance()->random_seed());
  STRING number = phonenumber->phoneNumber();
  for (STRING::const_iterator iter = number.begin(); iter != number.end(); ++iter) {
    if (isdigit(*iter) || *iter == '-' || *iter == '+' || *iter == '(' || *iter == ')' || *iter == ' ' || *iter == '%' || *iter == 'x' || *iter == '.')
      continue;
    ADD_FAILURE() << "What is this \"" << *iter << "\" doing in here..";
  };
  delete phonenumber;
};

TEST_F(en_CA_PhoneNumber, Operator) {
  cxxfaker::providers::en_CA::PhoneNumber phonenumber;
  phonenumber.Seed(::testing::UnitTest::GetInstance()->random_seed());
  STRING number = phonenumber;
  for (STRING::const_iterator iter = number.begin(); iter != number.end(); ++iter) {
    if (isdigit(*iter) || *iter == '-' || *iter == '+' || *iter == '(' || *iter == ')' || *iter == ' ' || *iter == '%' || *iter == 'x' || *iter == '.')
      continue;
    ADD_FAILURE() << "What is this \"" << *iter << "\" doing in here..";
  };
};

};