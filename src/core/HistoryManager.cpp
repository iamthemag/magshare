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
// $Id: HistoryManager.cpp 1560 2023-03-15 07:56:27Z mastroddi $
//
//////////////////////////////////////////////////////////////////////

#include "HistoryManager.h"
#include "Settings.h"


HistoryManager* HistoryManager::mp_instance = Q_NULLPTR;


HistoryManager::HistoryManager()
  : m_history(), m_index( 0 ), m_temporayMessage()
{
  m_history.append( m_temporayMessage );
}

bool HistoryManager::moveHistoryUp()
{
  if( m_index > maxIndex() )
    return false;
  m_index++;
  return true;
}

bool HistoryManager::moveHistoryDown()
{
  if( m_index < minIndex() )
    return false;
  m_index--;
  return true;
}

HistoryMessage HistoryManager::message() const
{
  if( m_history.isEmpty() || m_index < minIndex() )
    return HistoryMessage();
  else if( m_index > maxIndex() )
    return hasTemporaryMessage() ? m_temporayMessage : HistoryMessage();
  else
    return m_history.at( m_index );
}

void HistoryManager::addMessage( const HistoryMessage& hm )
{
  m_temporayMessage.clear();
  m_history.removeOne( hm ); // no duplicates
  m_history.append( hm );
  if( historySize() > Settings::instance().chatMessageHistorySize() )
    m_history.removeFirst();
  m_index = m_history.size(); // +1 from historySize
}
