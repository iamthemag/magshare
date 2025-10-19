
CONFIG(debug,debug|release) {
  message( Building MagShare in Debug Mode )
  DEFINES += MAGSHARE_DEBUG
} else {
  message( Building MagShare in Release Mode )
}

macx {
  CONFIG(debug,debug|release) {
    CONFIG -= app_bundle
    message( Building MagShare without BUNDLE )
  } else {
    # Disable app_bundle for GitHub Actions CI builds to make executable available at test/magshare
    # GitHub Actions sets CI=true and GITHUB_ACTIONS=true environment variables
    CI_BUILD = $$(CI)
    GITHUB_ACTIONS_BUILD = $$(GITHUB_ACTIONS)
    !isEmpty(CI_BUILD) {
      CONFIG -= app_bundle
      message( Building MagShare without BUNDLE for CI build )
    } else:!isEmpty(GITHUB_ACTIONS_BUILD) {
      CONFIG -= app_bundle
      message( Building MagShare without BUNDLE for GitHub Actions build )
    } else {
      CONFIG += app_bundle
      message( Building MagShare BUNDLE )
    }
  }
}

greaterThan(QT_MAJOR_VERSION, 5) {
  message(Qt version: $$[QT_VERSION])
} else {
  greaterThan(QT_MAJOR_VERSION, 4):!lessThan(QT_MINOR_VERSION, 15) {
    message(Qt version: $$[QT_VERSION])
  } else {
    message(Qt $$[QT_VERSION] is NOT SUPPORTED - required 5.15.0+)
    error(Unable to build MagShare with this Qt $$[QT_VERSION])
  }
}

include(../magshare.pri)

message( Target folder: $$DESTDIR )

TEMPLATE = app
#DEFINES += MAGSHARE_DISABLE_FILE_TRANSFER
#DEFINES += MAGSHARE_DISABLE_SEND_MESSAGE
#DEFINES += MAGSHARE_DISABLE_VIDEO_CALL
#DEFINES += MAGSHARE_USE_WEBENGINE

TARGET = magshare

QT += network xml widgets printsupport

win32|unix {
  QT += multimedia
#DEFINES += MAGSHARE_USE_VOICE_CHAT
}

unix:!macx:!android: {
  LIBS += -lxcb -lxcb-screensaver
  CONFIG += largefile
}

macx {
  QMAKE_LFLAGS += -F/System/Library/Frameworks/ApplicationServices.framework
  LIBS += -framework ApplicationServices
  QMAKE_INFO_PLIST = ../misc/Info.plist
}

win32 {
  DEFINES += _CRT_SECURE_NO_WARNINGS
  LIBS += -luser32
}

unix {
  contains(QMAKE_HOST.arch, armv7l* ): {
    DEFINES += MAGSHARE_FOR_RASPBERRY_PI
  }
}

message( Arch: $$QMAKE_HOST.arch )
message( Qt modules: $$QT )

include(../locale/locale.pri)
include(hunspell/hunspell.pri)
include(core/core.pri)
include(ecdh/ecdh.pri)
include(gui/gui.pri)
include(desktop/desktop.pri)
include(override/override.pri)
include(utils/utils.pri)
win32|unix {
  include(qxt/qxt.pri)
  include(sharedesktop/sharedesktop.pri)
  contains(DEFINES, MAGSHARE_USE_VOICE_CHAT) {
    include(voicechat/voicechat.pri)
  }
}

#!contains( DEFINES, MAGSHARE_DISABLE_VIDEO_CALL ) {
#  greaterThan( QT_MAJOR_VERSION, 4 ): {
#    greaterThan( QT_MINOR_VERSION, 4 ): {
#      message( Custom module added: videocall )
#      include(videocall/videocall.pri)
# } } } else {
#   message( Custom module disabled: videocall )
# }

HEADERS += Interfaces.h

RESOURCES += beebeep.qrc emojis.qrc
!contains(DEFINES, MAGSHARE_FOR_RASPBERRY_PI) {
  RESOURCES += emojis2x_1.qrc emojis2x_2.qrc
}

win32: RC_FILE = magshare.rc
macx: ICON = magshare.icns
macx: include(mdns/mdns.pri)

message( Config: $$CONFIG )
message( Libs: $$LIBS )
message( Defines: $$DEFINES )
message( Resources: $$RESOURCES )
macx: message( Info.plist: $$QMAKE_INFO_PLIST )
message( Object dir: $$OBJECTS_DIR )
unix: message( CXX flags: $$QMAKE_CXXFLAGS )
message( QT Plugins: $$QTPLUGIN )

unix:!macx:!android: {
  target.path = $$BINDIR
  INSTALLS += target
}
