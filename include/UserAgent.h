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

#ifndef _USERAGENT_H
#define _USERAGENT_H

#include "defines.h"

#include "Base.h"

namespace cxxfaker {
  namespace providers {
    class UserAgent : public Base {
    public:
      UserAgent(randGenerator* generator = NULL, randSeeder* seeder = NULL);
      virtual ~UserAgent() {};
      STRING Chrome();
      STRING Safari();
      STRING Opera();
      STRING InternetExplorer();

      STRING randomPlatformToken();
      STRING linuxPlatformToken();
      STRING macPlatformToken();
      STRING windowsPlatformToken();
    protected:
      std::vector<STRING> linuxCPUs;
      std::vector<STRING> macCPUs;
      std::vector<STRING> windowsPlatforms;
      std::vector<STRING> languages;
    };
  };
};

#endif //_USERAGENT_H