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
// $Id: GuiAskPassword.h 1560 2023-03-15 07:56:27Z mastroddi $
//
//////////////////////////////////////////////////////////////////////

#ifndef MAGSHARE_GUIASKPASSWORD_H
#define MAGSHARE_GUIASKPASSWORD_H

#include "Config.h"
#include "ui_GuiAskPassword.h"


class GuiAskPassword : public QDialog, private Ui::GuiAskPassword
{
  Q_OBJECT

public:
  GuiAskPassword( QWidget* parent = Q_NULLPTR );

  void loadData();

private slots:
  void somethingChanged();
  void okPressed();
  void connectionTypeChanged( int );

private:
  QButtonGroup m_bgPasswordType;

};

#endif // MAGSHARE_GUIASKPASSWORD_H
