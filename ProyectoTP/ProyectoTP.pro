#-------------------------------------------------
#
# Project created by QtCreator 2015-03-25T22:38:43
#
#-------------------------------------------------

QT       += widgets
win32:CONFIG(release,debug|release){
TARGET = ProyectoTP
}
else:win32:CONFIG(debug,debug|release) {
TARGET = ProyectoTPd
}

TEMPLATE = lib

DEFINES += PROYECTOTP_LIBRARY

INCLUDEPATH += ..
DESTDIR =../libs

SOURCES += archivoproyecto.cpp \
    aprotpsection.cpp \
    aprocnpmetortosection.cpp

HEADERS += archivoproyecto.h\
        proyectotp_global.h \
    aprotpsection.h \
    aprocnpmetortosection.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
