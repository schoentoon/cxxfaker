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

#include "DateTime.h"

#include <string.h>

using namespace cxxfaker::providers;

bool DateTime::initNow() {
  if (isInitialized())
    return false;
  time = std::time(NULL);
  return true;
};

bool DateTime::initBetween(std::time_t start, std::time_t end) {
  if (isInitialized())
    return false;
  time = randomInt(start, end);
  return true;
};

const STRING DateTime::ISO8601() const {
  char buf[BUFFER_SIZE];
  std::size_t len = strftime(buf, sizeof(buf), "%Y-%m-%dT%H:%M:%S%z", std::localtime(&time));
  return STRING(buf, len);
};

const STRING DateTime::format(const STRING& format, const std::locale& locale) const {
  std::locale::global(locale);
  size_t buflen = format.size();
  for (;;) {
    char buf[buflen];
    std::size_t len = strftime(buf, sizeof(buf), format.c_str(), std::localtime(&time));
    if (len > 0) {
      std::locale::global(std::locale::classic());
      return STRING(buf, len);
    };
    buflen *= 2;
  };
};

int DateTime::getYear() const {
  struct tm *t = std::localtime(&time);
  return 1900 + t->tm_year;
};

int DateTime::getMonth() const {
  struct tm *t = std::localtime(&time);
  return t->tm_mon;
};

int DateTime::getDayOfMonth() const {
  struct tm *t = std::localtime(&time);
  return t->tm_mday;
};

int DateTime::getSeconds() const {
  struct tm *t = std::localtime(&time);
  return t->tm_sec;
};

int DateTime::getMinutes() const {
  struct tm *t = std::localtime(&time);
  return t->tm_min;
};

int DateTime::getHours() const {
  struct tm *t = std::localtime(&time);
  return t->tm_hour;
};