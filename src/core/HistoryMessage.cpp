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
// $Id: HistoryMessage.cpp 1560 2023-03-15 07:56:27Z mastroddi $
//
//////////////////////////////////////////////////////////////////////

#include "HistoryMessage.h"


HistoryMessage::HistoryMessage()
 : m_message( "" ), m_emoticons()
{}

HistoryMessage::HistoryMessage( const HistoryMessage& hm )
{
  (void)operator=( hm );
}

HistoryMessage& HistoryMessage::operator=( const HistoryMessage& hm )
{
  if( this != &hm )
  {
    m_message = hm.m_message;
    m_emoticons = hm.m_emoticons;
  }
  return *this;
}

void HistoryMessage::clear()
{
  m_message = "";
  if( !m_emoticons.isEmpty() )
    m_emoticons.clear();
}
