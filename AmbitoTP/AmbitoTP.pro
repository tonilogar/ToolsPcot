#-------------------------------------------------
#
# Project created by QtCreator 2015-11-05T22:33:41
#
#-------------------------------------------------

QT       -= gui

TEMPLATE = lib

win32:CONFIG(release,debug|release):TARGET = AmbitoTP
else:win32:CONFIG(debug,debug|release):TARGET = AmbitoTPd
!win32:TARGET = AmbitoTP

INCLUDEPATH += ..
DESTDIR =../libs

DEFINES += AMBITOTP_LIBRARY

SOURCES += \
    ambito.cpp \
    ambitjson.cpp \
    ambevaluador.cpp \
    ambevaluatest.cpp \
    ambevextractiontest.cpp \
    ambevfootprinttest.cpp \
    ambevrangoutmtest.cpp \
    ambevgeotransformtest.cpp \
    ambevresizetest.cpp \
    ambevsubscenetest.cpp \
    ambevutmfranciatest.cpp

HEADERS +=\
        ambitotp_global.h \
    ambito.h \
    ambitjson.h \
    ambevaluador.h \
    ambevaluatest.h \
    ambevextractiontest.h \
    ambevfootprinttest.h \
    ambevrangoutmtest.h \
    ambevgeotransformtest.h \
    ambevresizetest.h \
    ambevsubscenetest.h \
    ambevutmfranciatest.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
