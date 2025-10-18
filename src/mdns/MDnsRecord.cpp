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
// $Id: MDnsRecord.cpp 1560 2023-03-15 07:56:27Z mastroddi $
//
//////////////////////////////////////////////////////////////////////

#include "MDnsRecord.h"


MDnsRecord::MDnsRecord()
  : m_serviceName( "" ), m_registeredType( "" ), m_replyDomain( "" )
{}

MDnsRecord::MDnsRecord( const MDnsRecord& br )
{
  (void)operator=( br );
}

MDnsRecord::MDnsRecord( const char *service_name, const char *registered_type, const char *reply_domain )
{
  m_serviceName = QString::fromUtf8( service_name );
  m_registeredType = QString::fromUtf8( registered_type );
  m_replyDomain = QString::fromUtf8( reply_domain );
}

MDnsRecord& MDnsRecord::operator=( const MDnsRecord& br )
{
  if( this != &br )
  {
    m_serviceName = br.m_serviceName;
    m_registeredType = br.m_registeredType;
    m_replyDomain = br.m_replyDomain;
  }
  return *this;
}
