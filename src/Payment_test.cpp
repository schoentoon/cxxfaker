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

#include "Payment.h"

#include "Base_test.h"

#include <arpa/inet.h>

using namespace cxxfaker::providers;

namespace tests {

class Payment : public ::tests::Base {
};

TEST_F(Payment, CreditCardType) {
  cxxfaker::providers::Payment* payment = new cxxfaker::providers::Payment();
  payment->Seed(::testing::UnitTest::GetInstance()->random_seed());
  STRING type = payment->creditCardType();
  if (!(type == "Visa" || type == "MasterCard" || type == "American Express" || type == "Discover Card")) {
    ADD_FAILURE() << "Got unexpected credit card type \"" << type << "\"";
  };
  delete payment;
};

TEST_F(Payment, CreditCardNumber) {
  cxxfaker::providers::Payment* payment = new cxxfaker::providers::Payment();
  payment->Seed(::testing::UnitTest::GetInstance()->random_seed());
  STRING number = payment->creditCardNumber();
  for (STRING::const_iterator iter = number.begin(); iter != number.end(); ++iter) {
    if (isdigit(*iter))
      continue;
    ADD_FAILURE() << "What is this \"" << *iter << "\" doing in here..";
  };
  number = payment->creditCardNumber("", true);
  int seperator_count = 0;
  for (STRING::const_iterator iter = number.begin(); iter != number.end(); ++iter) {
    if (isdigit(*iter))
      continue;
    else if (*iter == '-') {
      ++seperator_count;
      continue;
    };
    ADD_FAILURE() << "What is this \"" << *iter << "\" doing in here..";
  };
  EXPECT_EQ(3, seperator_count);
  delete payment;
};

};