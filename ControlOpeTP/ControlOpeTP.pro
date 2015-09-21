#-------------------------------------------------
#
# Project created by QtCreator 2015-01-27T00:08:27
#
#-------------------------------------------------

QT       += widgets
win32:CONFIG(release,debug|release){
TARGET = ControlOpeTP
LIBS += -L../libs -lOpePcot -lRegistroTP -lCoordinatesTP
}
else:win32:CONFIG(debug,debug|release) {
TARGET = ControlOpeTPd
LIBS += -L../libs -lOpePcotd -lRegistroTPd -lCoordinatesTPd
}
TEMPLATE = lib

DEFINES += CONTROLOPETP_LIBRARY

INCLUDEPATH += ..
DESTDIR =../libs


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
