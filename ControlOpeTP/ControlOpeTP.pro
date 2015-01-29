#-------------------------------------------------
#
# Project created by QtCreator 2015-01-27T00:08:27
#
#-------------------------------------------------

QT       += widgets

TARGET = ControlOpeTP
TEMPLATE = lib

DEFINES += CONTROLOPETP_LIBRARY

INCLUDEPATH += ..
DESTDIR =../libs
LIBS += -L../libs -lOpePcot

SOURCES += \
    lanzadoroperaciones.cpp \
    controlworker.cpp

HEADERS +=\
        controlopetp_global.h \
    controlworker.h \
    lanzadoroperaciones.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
