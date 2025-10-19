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
// $Id: Connection.h 1560 2023-03-15 07:56:27Z mastroddi $
//
//////////////////////////////////////////////////////////////////////

#ifndef MAGSHARE_CONNECTION_H
#define MAGSHARE_CONNECTION_H

#include "ConnectionSocket.h"
class Message;


class Connection : public ConnectionSocket
{
  Q_OBJECT

public:
  explicit Connection( QObject *parent = Q_NULLPTR );

  bool sendMessage( const Message& );
  void setReadyForUse( VNumber );
  inline bool isReadyForUse() const;

signals:
  void newMessage( VNumber, const Message& );

protected slots:
  void parseData( const QByteArray& );
  void sendPing();
  void sendPong();

};

// Inline Functions
inline bool Connection::isReadyForUse() const { return isHelloSent() && userId() != ID_INVALID; }

#endif // MAGSHARE_CONNECTION_H
