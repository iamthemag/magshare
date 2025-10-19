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
// $Id: UserStatusRecord.h 1560 2023-03-15 07:56:27Z mastroddi $
//
//////////////////////////////////////////////////////////////////////

#ifndef MAGSHARE_USERSTATUSRECORD_H
#define MAGSHARE_USERSTATUSRECORD_H

#include "Config.h"


class UserStatusRecord
{
public:
  UserStatusRecord();
  UserStatusRecord( const UserStatusRecord& );

  UserStatusRecord& operator=( const UserStatusRecord& );
  bool operator<( const UserStatusRecord& ) const;
  inline bool operator==( const UserStatusRecord& ) const;

  inline bool isValid() const;
  inline void setStatus( int );
  inline int status() const;
  inline void setStatusDescription( const QString& );
  inline const QString& statusDescription() const;

private:
  int m_status;
  QString m_statusDescription;

};


// Inline Functions
inline bool UserStatusRecord::operator==( const UserStatusRecord& usr ) const { return m_status == usr.m_status && m_statusDescription == usr.m_statusDescription; }
inline bool UserStatusRecord::isValid() const { return m_status >= 0; }
inline void UserStatusRecord::setStatus( int new_value ) { m_status = new_value; }
inline int UserStatusRecord::status() const { return m_status; }
inline void UserStatusRecord::setStatusDescription( const QString& new_value ) { m_statusDescription = new_value; }
inline const QString& UserStatusRecord::statusDescription() const { return m_statusDescription; }

#endif // MAGSHARE_USERSTATUSRECORD_H
