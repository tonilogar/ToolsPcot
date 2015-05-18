#-------------------------------------------------
#
# Project created by QtCreator 2015-01-26T23:26:57
#
#-------------------------------------------------

QT       += widgets

win32:CONFIG(release,debug|release){
TARGET = CnpMetOrtoTP
LIBS += -L../libs -lOpePcot
}
else:win32:CONFIG(debug,debug|release) {
TARGET = CnpMetOrtoTPd
LIBS += -L../libs -lOpePcotd
}
TEMPLATE = lib

DEFINES += CNPMETORTOTP_LIBRARY

INCLUDEPATH += ..
DESTDIR =../libs

win32:CONFIG(release, debug|release): LIBS += -L../libs -lProyectoTP
else:win32:CONFIG(debug, debug|release): LIBS += -L../libs -lProyectoTPd
else:unix:!macx: LIBS += -L../libs -lProyectoTP


SOURCES += \
    registrocreateorto.cpp \
    registrocreatemet.cpp \
    registrocreatecnps.cpp \
    createorto.cpp \
    createmet.cpp \
    createcnps.cpp \
    ficherodatosambitopro.cpp

HEADERS +=\
        cnpmetortotp_global.h \
    registrocreatemet.h \
    registrocreatecnps.h \
    registrocreateorto.h \
    createorto.h \
    createmet.h \
    createcnps.h \
    ficherodatosambitopro.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}


FORMS += \
    createmet.ui \
    createcnps.ui \
    createorto.ui
