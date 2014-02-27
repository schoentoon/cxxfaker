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

#include "UserAgent.h"

#include <cstdlib>
#include <sstream>
#include <iomanip>

using namespace cxxfaker::providers;

UserAgent::UserAgent(randGenerator* generator, randSeeder* seeder)
: Base(generator, seeder) {
  linuxCPUs.push_back("i686");
  linuxCPUs.push_back("x86_64");

  macCPUs.push_back("Intel");
  macCPUs.push_back("PPC");
  macCPUs.push_back("U; Intel");
  macCPUs.push_back("U; PPC");

  windowsPlatforms.push_back("Windows NT 6.2");
  windowsPlatforms.push_back("Windows NT 6.1");
  windowsPlatforms.push_back("Windows NT 6.0");
  windowsPlatforms.push_back("Windows NT 5.2");
  windowsPlatforms.push_back("Windows NT 5.1");
  windowsPlatforms.push_back("Windows NT 5.01");
  windowsPlatforms.push_back("Windows NT 5.0");
  windowsPlatforms.push_back("Windows NT 4.0");
  windowsPlatforms.push_back("Windows 98; Win 9x 4.90");
  windowsPlatforms.push_back("Windows 98");
  windowsPlatforms.push_back("Windows 95");
  windowsPlatforms.push_back("Windows CE");

  languages.push_back("bg_BG");
  languages.push_back("cs_CZ");
  languages.push_back("da_DK");
  languages.push_back("de_DE");
  languages.push_back("el_GR");
  languages.push_back("en_CA");
  languages.push_back("en_GB");
  languages.push_back("en_US");
  languages.push_back("en_ZA");
  languages.push_back("es_AR");
  languages.push_back("es_ES");
  languages.push_back("es_PE");
  languages.push_back("fi_FI");
  languages.push_back("fr_BE");
  languages.push_back("fr_FR");
  languages.push_back("hu_HU");
  languages.push_back("hy_AM");
  languages.push_back("is_IS");
  languages.push_back("it_IT");
  languages.push_back("ja_JP");
  languages.push_back("lv_LV");
  languages.push_back("nl_BE");
  languages.push_back("nl_NL");
  languages.push_back("pl_PL");
  languages.push_back("pt_BR");
  languages.push_back("ro_MD");
  languages.push_back("ru_RU");
  languages.push_back("sk_SK");
  languages.push_back("tr_TR");
  languages.push_back("uk_UA");
};

STRING UserAgent::Chrome() {
  int saf = (randomInt(531, 536) * 10) + randomInt(0, 2);
  std::stringstream output;
  output << "Mozilla/5.0 (";
  output << randomPlatformToken();
  output << ") AppleWebKit/";
  output << saf;
  output << " (KHTML, like Gecko) Chrome/";
  output << randomInt(30, 33); // TODO Calculate an average max version based upon time
  output << ".0.";             // Chrome has a 6 week release schedule so that shouldn't be too hard
  output << randomInt(800, 899);
  output << ".0 Safari/";
  output << saf;
  return STRING(output.str());
};

STRING UserAgent::Safari() {
  std::stringstream saf;
  saf << randomInt(531, 535) << "." << randomInt(1, 50) << "." << randomInt(1, 7);
  std::stringstream ver;
  if (randomInt(0, 1) == 0)
    ver << randomInt(4, 5) << "." << randomInt(0, 1);
  else
    ver << randomInt(4, 5) << ".0." << randomInt(1, 5);

  std::stringstream output;
  output << "Mozilla/5.0 ";
  switch (randomInt(0, 2)) {
  case 0:
    output << "(Windows; U; ";
    output << windowsPlatformToken();
    output << ") AppleWebKit/";
    output << saf.str();
    output << " (KHTML, like Gecko) Version/";
    output << ver.str();
    output << " Safari/";
    output << saf.str();
    break;
  case 1:
    output << "(";
    output << macPlatformToken();
    output << " rv:";
    output << randomInt(2, 6);
    output << ".0";
    output << *randomElement<STRING>(languages);
    output << ") AppleWebKit/";
    output << saf.str();
    output << " (KHTML, like Gecko) Version/";
    output << ver.str();
    output << " Safari/";
    output << saf.str();
    break;
  case 2:
    output << "(iPod; U; CPU iPhone OS ";
    output << randomInt(4, 7);
    output << "_";
    output << randomInt(0, 3);
    output << " like Mac OS X; ";
    output << *randomElement<STRING>(languages);
    output << ") AppleWebKit/$saf (KHTML, like Gecko) Version/";
    output << randomInt(3, 4);
    output << ".0.5 Mobile/8B";
    output << randomInt(111, 119);
    output << " Safari/6";
    output << saf.str();
    break;
  };
  return STRING(output.str());
};

STRING UserAgent::Opera() {
  std::stringstream output;
  output << "Opera/";
  output << randomInt(8, 9);
  output << ".";
  output << randomInt(10, 99);
  output << " (";
  switch (randomInt() % 2) {
  case 0:
    output << linuxPlatformToken();
    break;
  case 1:
    output << windowsPlatformToken();
    break;
  };
  output << "; ";
  output << *randomElement<STRING>(languages);
  output << ") Presto/2.9.";
  output << randomInt(160, 190);
  output << " Version/";
  output << randomInt(10, 12);
  output << ".00";
  return STRING(output.str());
};

STRING UserAgent::InternetExplorer() {
  std::stringstream output;
  output << "Mozilla/5.0 (compatible; MSIE ";
  output << randomInt(5, 9);
  output << ".0; ";
  output << windowsPlatformToken();
  output << "; Trident/";
  output << randomInt(3, 5);
  output << ".";
  output << randomInt(0, 1);
  output << ")";
  return STRING(output.str());
};

STRING UserAgent::randomPlatformToken() {
  switch (randomInt(0, 2)) {
  case 0:
    return linuxPlatformToken();
  case 1:
    return macPlatformToken();
  case 2:
    return windowsPlatformToken();
  default:
    return "";
  }
};

STRING UserAgent::linuxPlatformToken() {
  STRING output = "X11; Linux ";
  output += *randomElement<STRING>(linuxCPUs);
  return output;
};

STRING UserAgent::macPlatformToken() {
  std::stringstream output;
  output << "Macintosh; ";
  output << *randomElement<STRING>(macCPUs);
  output << " Mac OS X 10_";
  output << randomInt(5, 8);
  output << "_";
  output << randomInt(0, 9);
  return STRING(output.str());
};

STRING UserAgent::windowsPlatformToken() {
  return *randomElement<STRING>(windowsPlatforms);
};