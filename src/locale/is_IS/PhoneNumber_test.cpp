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

#include "locale/is_IS/PhoneNumber.h"

#include "Base_test.h"

using namespace cxxfaker::providers;

namespace tests {

class is_IS_PhoneNumber : public ::tests::Base {
};

TEST_F(is_IS_PhoneNumber, PhoneNumber) {
  cxxfaker::providers::is_IS::PhoneNumber* phonenumber = new cxxfaker::providers::is_IS::PhoneNumber();
  phonenumber->Seed(::testing::UnitTest::GetInstance()->random_seed());
  STRING number = phonenumber->phoneNumber();
  for (STRING::const_iterator iter = number.begin(); iter != number.end(); ++iter) {
    if (isdigit(*iter) || *iter == '+' || *iter == ' ')
      continue;
    ADD_FAILURE() << "What is this \"" << *iter << "\" doing in here..";
  };
  delete phonenumber;
};

TEST_F(is_IS_PhoneNumber, Operator) {
  cxxfaker::providers::is_IS::PhoneNumber phonenumber;
  phonenumber.Seed(::testing::UnitTest::GetInstance()->random_seed());
  STRING number = phonenumber;
  for (STRING::const_iterator iter = number.begin(); iter != number.end(); ++iter) {
    if (isdigit(*iter) || *iter == '+' || *iter == ' ')
      continue;
    ADD_FAILURE() << "What is this \"" << *iter << "\" doing in here..";
  };
};

};