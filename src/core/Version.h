//////////////////////////////////////////////////////////////////////
//
// MagShare Copyright (C) 2010-2023 Marco Mastroddi
//
// MagShare is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published
// by the Free Software Foundation, either version 3 of the License,
// or (at your option) any later version.
//
// MagShare is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with MagShare. If not, see <http://www.gnu.org/licenses/>.
//
// Author: Marco Mastroddi <marco.mastroddi(AT)gmail.com>
//
// $Id: Version.h 1371 2024-04-20 09:16:57Z mastroddi $
//
//////////////////////////////////////////////////////////////////////

#ifndef BEEBEEP_VERSION_H
#define BEEBEEP_VERSION_H

const char BEEBEEP_NAME[] = "MagShare";
const char BEEBEEP_ORGANIZATION[] = "MagShareSW";
const char MAGSHARE_ORGANIZATION_DOMAIN[] = "magshare.net";
const char MAGSHARE_DNS_RECORD[] = "_magshare._tcp";
const char BEEBEEP_WEBSITE[] = "https://github.com/iamthemag/magshare";
const char MAGSHARE_DOWNLOAD_WEBSITE[] = "";
const char MAGSHARE_DONATE_WEBSITE[] = "";
const char MAGSHARE_HELP_WEBSITE[] = "https://github.com/iamthemag/magshare";
const char MAGSHARE_LANGUAGE_WEBSITE[] = "language";
const char MAGSHARE_NEWS_WEBSITE[] = "news";
const char MAGSHARE_CHECK_VERSION_WEBSITE[] = "check_version.php";
const char MAGSHARE_LAST_VERSION_FILE[] = "/releases/latest/download/VERSION.json";
const char MAGSHARE_FACT_WEBSITE[] = "fact";
const char MAGSHARE_TIPS_WEBSITE[] = "tips";
const char MAGSHARE_FAQ_WEBSITE[] = "faq";
const char MAGSHARE_GA_TRACKING_ID[] = "UA-57878696-4";
const char MAGSHARE_GA_URL[] = "https://www.google-analytics.com/collect";
const char MAGSHARE_GA_EVENT_VERSION[] = "1";
const char HUNSPELL_VERSION[] = "1.7.0";
const char BEEBEEP_VERSION[] = "1.1.1";
const int BEEBEEP_PROTO_VERSION = 95;
const int BEEBEEP_SETTINGS_VERSION = 18;
const int BEEBEEP_BUILD = 1371;

// MagShare constant mappings for backward compatibility
#define MAGSHARE_NAME BEEBEEP_NAME
#define MAGSHARE_VERSION BEEBEEP_VERSION
#define MAGSHARE_PROTO_VERSION BEEBEEP_PROTO_VERSION
#define MAGSHARE_SETTINGS_VERSION BEEBEEP_SETTINGS_VERSION
#define MAGSHARE_BUILD BEEBEEP_BUILD
#define MAGSHARE_ORGANIZATION BEEBEEP_ORGANIZATION
#define MAGSHARE_WEBSITE BEEBEEP_WEBSITE

#endif // BEEBEEP_VERSION_H

