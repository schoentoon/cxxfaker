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

#ifndef _DATETIME_H
#define _DATETIME_H

#include "Base.h"

#include <ctime>
#include <locale>

namespace cxxfaker {
  namespace providers {
    class DateTime : public Base {
    public:
      DateTime(randGenerator* generator = NULL, randSeeder* seeder = NULL)
      : Base(generator, seeder) {
        time = 0;
      };
      virtual ~DateTime() {};
      bool initNow();
      bool initBetween(std::time_t start = 0, std::time_t end = std::time(NULL));
      bool initThisYear() {
        return initBetween(std::time(NULL) - (60 * 60 * 24 * 365));
      };
      bool initThisMonth() {
        return initBetween(std::time(NULL) - (60 * 60 * 24 * 30));
      };
      bool initThisDecade() {
        return initBetween(std::time(NULL) - (60 * 60 * 24 * 365 * 10));
      };
      bool isInitialized() const { return time != 0; };

      const std::time_t unixTime() const { return time; };
      const STRING ISO8601() const;
      const STRING format(const STRING& format, const std::locale& locale = std::locale("")) const;
      int getYear() const;
      int getMonth() const;
      int getDayOfMonth() const;
      int getSeconds() const;
      int getMinutes() const;
      int getHours() const;
    private:
      std::time_t time;
    };
  };
};

#endif //_DATETIME_H