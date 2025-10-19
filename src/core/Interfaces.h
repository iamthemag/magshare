//////////////////////////////////////////////////////////////////////
//
// This file is part of MagShare.
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
// along with MagShare.  If not, see <http://www.gnu.org/licenses/>.
//
// Author: Marco Mastroddi <marco.mastroddi(AT)gmail.com>
//
// $Id: Interfaces.h 700 2016-03-21 19:32:34Z mastroddi $
//
//////////////////////////////////////////////////////////////////////

#ifndef MAGSHARE_INTERFACES_H
#define MAGSHARE_INTERFACES_H

#include <QtPlugin>
#include <QIcon>


class PluginInterface
{
public:
  virtual ~PluginInterface() {}

  inline void setEnabled( bool );
  inline bool isEnabled() const;

  virtual QString name() const = 0;
  virtual QString version() const = 0;
  virtual QString help() const = 0;
  virtual QString author() const = 0;
  virtual QIcon icon() const = 0;
  virtual QString iconFileName() const = 0;

  // Priority: 100 High, 1000 Normal, 10000 Low
  virtual int priority() const = 0;

  virtual QString coreVersion() const = 0;

protected:
  bool m_isEnabled;

};

class TextMarkerInterface : public PluginInterface
{
public:
  virtual bool parseBeforeSending() const = 0;

  virtual QString openCommand() const = 0;
  virtual QString closeCommand() const = 0;
  virtual QString openString() const = 0;
  virtual QString closeString() const = 0;
  virtual void initParser( const QString& ) = 0; // pass the string between open and close command
  virtual QString parseString( const QString& ) = 0; // FALSE break the loop

};

class ServiceInterface : public PluginInterface
{
public:
  virtual QString protocol() const = 0;
  virtual QString hostAddress() const = 0;
  virtual int hostPort() const = 0;

  virtual bool fileTransferIsEnabled() const = 0;

  virtual QString userStatusOfflineIconPath() const = 0;
  virtual QString userStatusOnlineIconPath() const = 0;
  virtual QString userStatusBusyIconPath() const = 0;
  virtual QString userStatusAwayIconPath() const = 0;

};

class GameInterface : public PluginInterface
{
public:
  virtual QWidget* mainWindow() const = 0;

  virtual void pause() = 0;
  virtual bool isPaused() const = 0;
  virtual void setSettings( QStringList ) = 0;
  virtual QStringList settings() const = 0;

};

// Inline Functions
inline void PluginInterface::setEnabled( bool new_value ) { m_isEnabled = new_value; }
inline bool PluginInterface::isEnabled() const { return m_isEnabled; }

#if QT_VERSION >= 0x050000
Q_DECLARE_INTERFACE( TextMarkerInterface, "magshare.plugin.TextMarkerInterface/2.0" )
Q_DECLARE_INTERFACE( ServiceInterface, "magshare.plugin.ServiceInterface/2.0" )
Q_DECLARE_INTERFACE( GameInterface, "magshare.plugin.GameInterface/2.0" )
#else
Q_DECLARE_INTERFACE( TextMarkerInterface, "magshare.plugin.TextMarkerInterface/1.5" )
Q_DECLARE_INTERFACE( ServiceInterface, "magshare.plugin.ServiceInterface/1.0" )
Q_DECLARE_INTERFACE( GameInterface, "magshare.plugin.GameInterface/1.0" )
#endif


#endif // MAGSHARE_INTERFACES_H
