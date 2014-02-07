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

#include "locale/tr_TR/PhoneNumber.h"

#include "Base_test.h"

using namespace cxxfaker::providers;

namespace tests {

class tr_TR_PhoneNumber : public ::tests::Base {
};

TEST_F(tr_TR_PhoneNumber, PhoneNumber) {
  cxxfaker::providers::tr_TR::PhoneNumber* phonenumber = new cxxfaker::providers::tr_TR::PhoneNumber();
  phonenumber->Seed(::testing::UnitTest::GetInstance()->random_seed());
  STRING number = phonenumber->phoneNumber();
  for (STRING::const_iterator iter = number.begin(); iter != number.end(); ++iter) {
    if (isdigit(*iter))
      continue;
    ADD_FAILURE() << "What is this \"" << *iter << "\" doing in here..";
  };
  delete phonenumber;
};

TEST_F(tr_TR_PhoneNumber, Operator) {
  cxxfaker::providers::tr_TR::PhoneNumber phonenumber;
  phonenumber.Seed(::testing::UnitTest::GetInstance()->random_seed());
  STRING number = phonenumber;
  for (STRING::const_iterator iter = number.begin(); iter != number.end(); ++iter) {
    if (isdigit(*iter))
      continue;
    ADD_FAILURE() << "What is this \"" << *iter << "\" doing in here..";
  };
};

};