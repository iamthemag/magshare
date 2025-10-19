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
// $Id: Config.h 1567 2023-04-05 07:01:29Z mastroddi $
//
//////////////////////////////////////////////////////////////////////

#ifndef MAGSHARE_CONFIG_H
#define MAGSHARE_CONFIG_H

#include <QtCore>
#include <QtGui>
#include <QtNetwork>
#include <QtWidgets>
#if !defined Q_OS_OS2
  #include <QtMultimedia>
#endif
#include <QtPrintSupport>
#ifdef MAGSHARE_USE_WEBENGINE
  #include <QWebEngineView>
#endif

// Type definition: define doesn't always work in signal slot mechanish
typedef quint64 VNumber;
typedef qint64 FileSizeType;

// Datastream QDataStream::Qt_4_0 = 7
#define DATASTREAM_VERSION_1 7

// Datastream QDataStream::Qt_4_8 = QDataStream::Qt_4_6 = 12
#define DATASTREAM_VERSION_2 12

#define LAST_DATASTREAM_VERSION DATASTREAM_VERSION_2

const int MAX_SOCKET_PORT = 65535;
// Broadcast
const int DEFAULT_BROADCAST_PORT = 36475;
const int DEFAULT_LISTENER_PORT = 6475;
const int DEFAULT_FILE_TRANSFER_PORT = 6476;

// Multicast
const char DEFAULT_IPV4_MULTICAST_ADDRESS[] = "224.0.64.75";
const char DEFAULT_IPV6_MULTICAST_ADDRESS[] = "FF05::6475";
const int DEFAULT_IPV4_MULTICAST_TTL_OPTION = 4;

// Connection I/O
typedef quint16 DATA_BLOCK_SIZE_16;
// set the limit to 65535 - sizeof( quint16 ) ... or a value near it
const DATA_BLOCK_SIZE_16 DATA_BLOCK_SIZE_16_LIMIT = 65519;

typedef quint32 DATA_BLOCK_SIZE_32;
//Due to compiler warning (ISO C90) the value 4294967295 of quint32 is not possibile... use qint32 - sizeof( qint32 )
const qint32 DATA_BLOCK_SIZE_32_LIMIT = 2147483615;
#define ENCRYPTED_DATA_BLOCK_SIZE 16
#define ENCRYPTION_KEYBITS 256
#define MAX_NUM_OF_LOOP_IN_CONNECTON_SOCKECT 40

// Protocol version steps
const int SECURE_LEVEL_2_PROTO_VERSION = 60;
const int FILE_TRANSFER_2_PROTO_VERSION = 63;
const int HIVE_PROTO_VERSION = 64;
const int NEW_GROUP_PROTO_VERSION = 67;
const int UTC_TIMESTAMP_PROTO_VERSION = 68;
#ifdef MAGSHARE_USE_SHAREDESKTOP
  const int SHARE_DESKTOP_PROTO_VERSION = 72;
#endif
const int SECURE_LEVEL_3_PROTO_VERSION = 73;
const int AUTORESPONDER_MESSAGE_PROTO_VERSION = 74;
const int SAVE_MESSAGE_AUTH_CODE_PROTO_VERSION = 76;
const int ENCRYPTION_CAN_BE_DISABLED_PROTO_VERSION = 80;
const int FILE_TRANSFER_RESUME_PROTO_VERSION = 82;
const int DATA_COMPRESSED_PROTO_VERSION = 84;
const int FILE_TRANSFER_UTC_MODIFIED_DATE_PROTO_VERSION = 86;
const int FILE_TRANSFER_MIMETYPE_IN_SHARE_PROTO_VERSION = 88;
const int SECURE_LEVEL_4_PROTO_VERSION = 90;
const int VCARD_ROOM_LOCATION_PROTO_VERSION = 91;
const int RECEIVED_MESSAGE_PROTO_VERSION = 93;
const int SOURCE_CODE_MESSAGE_PROTO_VERSION = 95;

// Tick interval in ms
const int TICK_INTERVAL = 1000;
const int PING_INTERVAL_IDLE = 4700;
const int PING_INTERVAL_TICK = 7;
const int PONG_DEFAULT_TIMEOUT = 21000;
const int TICK_INTERVAL_CONNECTION_TIMEOUT = 16;
const int DELAY_CONTACT_USERS = 9000;

// Protocol
const VNumber ID_INVALID                = 0;
const VNumber ID_LOCAL_USER             = 1;
const VNumber ID_DEFAULT_CHAT           = 2;
const VNumber ID_START                  = 1000;
const VNumber ID_SYSTEM_MESSAGE         = 10;
const VNumber ID_BEEP_MESSAGE           = 11;
const VNumber ID_WRITING_MESSAGE        = 12;
const VNumber ID_PING_MESSAGE           = 13;
const VNumber ID_PONG_MESSAGE           = 14;
const VNumber ID_HELLO_MESSAGE          = 15;
const VNumber ID_USER_MESSAGE           = 16;
const VNumber ID_VCARD_MESSAGE          = 17;
const VNumber ID_SHARE_MESSAGE          = 18;
const VNumber ID_SHAREBOX_MESSAGE       = 19;
const VNumber ID_DOTDOT_FOLDER          = 20;
const VNumber ID_SHAREDESKTOP_MESSAGE   = 21;
const VNumber ID_BUZZ_MESSAGE           = 22;
const VNumber ID_IMPORTANT_MESSAGE      = 23;
const VNumber ID_TEST_MESSAGE           = 24;
const VNumber ID_HELP_MESSAGE           = 25;
const VNumber ID_RECEIVED_MESSAGE       = 26;

#endif // MAGSHARE_CONFIG_H
