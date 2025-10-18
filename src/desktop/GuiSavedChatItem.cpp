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
// $Id: GuiSavedChatItem.cpp 1560 2023-03-15 07:56:27Z mastroddi $
//
//////////////////////////////////////////////////////////////////////

#include "GuiSavedChatItem.h"
#include "GuiChatItem.h"


GuiSavedChatItem::GuiSavedChatItem( QTreeWidget* parent )
 : QTreeWidgetItem( parent )
{
}

bool GuiSavedChatItem::operator<( const QTreeWidgetItem& item ) const
{
  return text( 0 ).toLower() < item.text( 0 ).toLower();
}
