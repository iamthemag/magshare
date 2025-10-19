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
// $Id: GuiPresetMessageList.h 1560 2023-03-15 07:56:27Z mastroddi $
//
//////////////////////////////////////////////////////////////////////

#ifndef MAGSHARE_GUIPRESETMESSAGELIST_H
#define MAGSHARE_GUIPRESETMESSAGELIST_H

#include "Config.h"


class GuiPresetMessageList : public QTreeWidget
{
  Q_OBJECT

public:
  GuiPresetMessageList( QWidget* parent = Q_NULLPTR );

  virtual QSize sizeHint() const;
  void loadFromSettings();

signals:
  void presetMessageSelected( const QString& );
  void updateRequest();

protected slots:
  void onDoubleClicked( QTreeWidgetItem*, int );
  void showContextMenu( const QPoint& );

protected:
  void onNew();
  void onRename( QTreeWidgetItem* );
  void onEdit( QTreeWidgetItem* );
  void onRemove( QTreeWidgetItem* );
  void savePreset( const QString& preset_key, const QString& preset_value );
  void removePreset( const QString& preset_key );

private:
  QAction* mp_actNew;
  QAction* mp_actRename;
  QAction* mp_actEdit;
  QAction* mp_actRemove;

};


#endif // MAGSHARE_GUIPRESETMESSAGELIST_H
