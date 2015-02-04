#-------------------------------------------------
#
# Project created by QtCreator 2015-01-26T23:02:53
#
#-------------------------------------------------

QT       += widgets

win32:CONFIG(release,debug|release):TARGET = ComponentesTP
else:win32:CONFIG(debug,debug|release):TARGET = ComponentesTPd
TEMPLATE = lib

INCLUDEPATH += ..
DESTDIR =../libs

DEFINES += COMPONENTESTP_LIBRARY

SOURCES += \
    indexbutton.cpp

HEADERS +=\
        componentestp_global.h \
    indexbutton.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
