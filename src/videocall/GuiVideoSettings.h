//////////////////////////////////////////////////////////////////////
//
// This file is part of MagShare.
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
// along with MagShare.  If not, see <http://www.gnu.org/licenses/>.
//
// Author: Marco Mastroddi <marco.mastroddi(AT)gmail.com>
//
// $Id: GuiVideoSettings.h 1125 2019-06-17 16:57:22Z mastroddi $
//
//////////////////////////////////////////////////////////////////////

#ifndef MAGSHARE_GUIVIDEOSETTINGS_H
#define MAGSHARE_GUIVIDEOSETTINGS_H

#include "Config.h"
#include "ui_GuiVideoSettings.h"


class GuiVideoSettings: public QWidget, private Ui::GuiVideoSettingsWidget
{
  Q_OBJECT

public:
  explicit GuiVideoSettings( QWidget *parent = Q_NULLPTR );

public slots:
  void saveSettings();
  void closeSettings();


};


#endif // MAGSHARE_GUIVIDEOSETTINGS_H
