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
// $Id: FirewallManager.h 1560 2023-03-15 07:56:27Z mastroddi $
//
//////////////////////////////////////////////////////////////////////

#ifndef MAGSHARE_FIREWALLMANAGER_H
#define MAGSHARE_FIREWALLMANAGER_H

#include "Config.h"


class FirewallManager
{
// Singleton Object
  static FirewallManager* mp_instance;

public:
  bool allowApplication( const QString& app_name, const QString& app_path );

  static FirewallManager& instance()
  {
    if( !mp_instance )
      mp_instance = new FirewallManager();
    return *mp_instance;
  }

  static void close()
  {
    if( mp_instance )
    {
      delete mp_instance;
      mp_instance = Q_NULLPTR;
    }
  }

protected:
  FirewallManager();


};

#endif // MAGSHARE_FIREWALLMANAGER_H
