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
// $Id: SaveChatList.h 1560 2023-03-15 07:56:27Z mastroddi $
//
//////////////////////////////////////////////////////////////////////

#ifndef MAGSHARE_GUISAVECHATLIST_H
#define MAGSHARE_GUISAVECHATLIST_H

#include "Config.h"


class SaveChatList : public QObject
{
  Q_OBJECT

public:
  explicit SaveChatList( QObject* parent = Q_NULLPTR );

  static bool canBeSaved();

signals:
  void operationCompleted();

public slots:
  bool save();
  bool autoSave();

protected:
  bool saveToFile( const QString&, bool silent_mode );
  bool saveChats( QDataStream*, bool silent_mode );

};

#endif // MAGSHARE_GUISAVECHATLIST_H
