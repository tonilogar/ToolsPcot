#-------------------------------------------------
#
# Project created by QtCreator 2015-01-26T23:26:57
#
#-------------------------------------------------

QT       += widgets

TARGET = CnpMetOrtoTP
TEMPLATE = lib

DEFINES += CNPMETORTOTP_LIBRARY

INCLUDEPATH += ..
DESTDIR =../libs
LIBS += -L../libs -lOpePcot

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
