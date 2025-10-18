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
// $Id: GuiNetwork.h 1560 2023-03-15 07:56:27Z mastroddi $
//
//////////////////////////////////////////////////////////////////////

#ifndef BEEBEEP_GUINETWORK_H
#define BEEBEEP_GUINETWORK_H

#include "Config.h"
#include "ui_GuiNetwork.h"


class GuiNetwork : public QDialog, private Ui::GuiNetworkWidget
{
  Q_OBJECT

public:
  GuiNetwork( QWidget* parent = Q_NULLPTR );

  void loadSettings();
  inline bool restartConnection() const;

protected slots:
  void checkAndSearch();
  void showFileHosts();
  void enableSearchUsersInterval();

private:
  bool m_restartConnection;

};

// Inline Functions
inline bool GuiNetwork::restartConnection() const { return m_restartConnection; }

#endif // BEEBEEP_GUINETWORK_H
