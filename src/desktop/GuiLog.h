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
// $Id: GuiLog.h 1560 2023-03-15 07:56:27Z mastroddi $
//
//////////////////////////////////////////////////////////////////////

#ifndef BEEBEEP_GUILOG_H
#define BEEBEEP_GUILOG_H

#include "Config.h"


class GuiLog : public QMainWindow
{
  Q_OBJECT

public:
  explicit GuiLog( QWidget *parent = Q_NULLPTR );

  void showUp();
  void startCheckingLog();
  void stopCheckingLog();

protected slots:
  void refreshLog();
  void findTextInLog();
  void saveLogAs();
  void logToFile( bool );
  void openLogMenu( const QPoint& );
  void openLogFilePath();

protected:
  void setupToolBar( QToolBar* );
  void closeEvent( QCloseEvent* );

private:
  QPlainTextEdit *mp_teLog;
  QTimer m_timer;

  QLineEdit* mp_leFilter;
  QCheckBox* mp_cbCaseSensitive;
  QCheckBox* mp_cbWholeWordOnly;
  QCheckBox* mp_cbLogToFile;
  QToolBar* mp_barLog;
  QMenu* mp_logMenu;
  QAction* mp_actOpenLogFilePath;

};

#endif // BEEBEEP_GUILOG_H
