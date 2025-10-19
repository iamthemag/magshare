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
// $Id: ShareDesktop.h 1560 2023-03-15 07:56:27Z mastroddi $
//
//////////////////////////////////////////////////////////////////////

#ifndef MAGSHARE_SHAREDESKTOP_H
#define MAGSHARE_SHAREDESKTOP_H

#include "ShareDesktopData.h"
class Chat;
class ShareDesktopJob;


class ShareDesktop : public QObject
{
  Q_OBJECT

public:
  explicit ShareDesktop( QObject* parent = Q_NULLPTR );

  bool start();
  void stop();
  inline bool isActive() const;

  bool addUserId( VNumber );
  bool removeUserId( VNumber );
  inline bool hasUsers() const;
  inline const QList<VNumber>& userIdList() const;
  void resetUserReadImage( VNumber );
  inline bool hasUserReadImage( VNumber ) const;
  void requestImageFromUser( VNumber );

signals:
  void imageDataAvailable( const ShareDesktopData& );
  void imageAvailable( const QImage& );

protected slots:
  void onImageDataAvailable( const QByteArray&, const QString& image_type, bool use_compression, unsigned int diff_color );
  void onScreenshotTimeout();

private:
  QList<VNumber> m_userIdList;
  QTimer m_timer;
  ShareDesktopJob* mp_job;
  ShareDesktopData m_lastImageData;
  QList<VNumber> m_userIdReadList;

};

// Inline Functions
inline bool ShareDesktop::hasUsers() const { return !m_userIdList.isEmpty(); }
inline const QList<VNumber>& ShareDesktop::userIdList() const { return m_userIdList; }
inline bool ShareDesktop::isActive() const { return m_timer.isActive(); }
inline bool ShareDesktop::hasUserReadImage( VNumber user_id ) const { return m_userIdReadList.contains( user_id ); }

#endif // MAGSHARE_SHAREDESKTOP_H
