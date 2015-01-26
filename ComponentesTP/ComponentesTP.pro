#-------------------------------------------------
#
# Project created by QtCreator 2015-01-26T23:02:53
#
#-------------------------------------------------

QT       += widgets

TARGET = ComponentesTP
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
