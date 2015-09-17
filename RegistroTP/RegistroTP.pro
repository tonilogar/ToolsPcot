#-------------------------------------------------
#
# Project created by QtCreator 2015-01-26T23:26:57
#
#-------------------------------------------------

QT       += widgets

win32:CONFIG(release,debug|release){
TARGET = RegistroTP
LIBS += -L../libs -lOpePcot
}
else:win32:CONFIG(debug,debug|release) {
TARGET = RegistroTP
LIBS += -L../libs -lOpePcotd
}
TEMPLATE = lib


DEFINES += REGISTROTP_LIBRARY

INCLUDEPATH += ..
DESTDIR =../libs

win32:CONFIG(release, debug|release): LIBS += -L../libs -lProyectoTP
else:win32:CONFIG(debug, debug|release): LIBS += -L../libs -lProyectoTPd
else:unix:!macx: LIBS += -L../libs -lProyectoTP

SOURCES += \
    registrocnp.cpp \
    registromet.cpp \
    registroorto.cpp

HEADERS +=\
        registrotp_global.h \
    registrocnp.h \
    registromet.h \
    registroorto.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}





