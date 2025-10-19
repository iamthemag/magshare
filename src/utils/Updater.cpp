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
// $Id: Updater.cpp 1560 2023-03-15 07:56:27Z mastroddi $
//
//////////////////////////////////////////////////////////////////////

#include "HttpDownloader.h"
#include "Settings.h"
#include "Updater.h"
#include <QJsonDocument>
#include <QJsonObject>


Updater::Updater( QObject *parent )
 : QObject( parent ), m_versionAvailable( "" ), m_downloadUrl( "" ), m_news( "" )
{
  setObjectName( "Updater" );
}

void Updater::checkForNewVersion()
{
  m_versionAvailable = "";
  m_downloadUrl = "";
  m_news = "";
  QUrl url( Settings::instance().lastVersionUrl() );

  HttpDownloader* http_downloader = new HttpDownloader( this );
  connect( http_downloader, SIGNAL( downloadCompleted( const QString& ) ),this, SLOT( onDownloadCompleted( const QString& ) ), Qt::QueuedConnection );
  connect( http_downloader, SIGNAL( jobFinished() ), this, SIGNAL( jobCompleted() ) );

  http_downloader->setOverwriteExistingFiles( true );
  http_downloader->addUrl( url );

  QMetaObject::invokeMethod( http_downloader, "startDownload", Qt::QueuedConnection );
}

void Updater::onDownloadCompleted( const QString& file_path )
{
  HttpDownloader* http_downloader = qobject_cast<HttpDownloader*>( sender() );
  if( !http_downloader )
  {
    qWarning() << "Updater received a signal from invalid HttpDownloader instance";
    return;
  }

#ifdef BEEBEEP_DEBUG
  qDebug() << qPrintable( file_path ) << "download completed";
#endif

  QFile jsonFile( file_path );
  if( jsonFile.open( QIODevice::ReadOnly ) )
  {
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson( jsonFile.readAll(), &parseError );
    jsonFile.close();
    
    if( parseError.error == QJsonParseError::NoError && doc.isObject() )
    {
      QJsonObject obj = doc.object();
      m_versionAvailable = obj["version"].toString();
      m_news = obj["release_notes"].toString();
      
      // Get download URL for current OS
      QString os = Settings::instance().operatingSystem( false ).toLower();
      QJsonObject downloads = obj["downloads"].toObject();
      if( downloads.contains( os ) )
      {
        m_downloadUrl = downloads[os].toString();
      }
      else
      {
        // Fallback - use the release page URL
        m_downloadUrl = QString( "https://github.com/iamthemag/magshare/releases/tag/%1" ).arg( obj["tag"].toString() );
      }
    }
  }

  if( m_versionAvailable.isEmpty() )
    qWarning() << file_path << "is not valid to check new version";

  if( !m_downloadUrl.isEmpty() )
  {
    QUrl url = QUrl::fromUserInput( m_downloadUrl );
    m_downloadUrl = url.toString();
  }

  QFile file_downloaded( file_path );
  if( !file_downloaded.remove() )
  {
    qWarning() << "Unable to remove file" << file_path << "now so it is added to temporaty files";
    Settings::instance().addTemporaryFilePath( file_path );
  }

  http_downloader->cleanUp();
}
