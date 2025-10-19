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
// $Id: Message.cpp 1560 2023-03-15 07:56:27Z mastroddi $
//
//////////////////////////////////////////////////////////////////////

#include "Message.h"


Message::Message()
  : m_type( Undefined ), m_id( ID_INVALID ), m_flags( 0 ), m_data( "" ),
    m_timestamp(), m_text( "" )
{
}

Message::Message( const Message& m )
{
  (void)operator=( m );
}

Message::Message( Type msg_type, VNumber msg_id, const QString& msg_txt )
  : m_type( msg_type ), m_id( msg_id ), m_flags( 0 ), m_data( "" ),
    m_timestamp( QDateTime::currentDateTime() ), m_text( msg_txt )
{
}

Message& Message::operator=( const Message& m )
{
  if( this != &m )
  {
    m_type = m.m_type;
    m_id = m.m_id;
    m_flags = m.m_flags;
    m_data = m.m_data;
    m_timestamp = m.m_timestamp;
    m_text = m.m_text;
  }
  return *this;
}
