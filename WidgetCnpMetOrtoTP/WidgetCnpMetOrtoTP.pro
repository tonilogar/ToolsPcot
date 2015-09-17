#-------------------------------------------------
#
# Project created by QtCreator 2015-01-26T23:26:57
#
#-------------------------------------------------

QT       += widgets

win32:CONFIG(release,debug|release){
TARGET = WidgetCnpMetOrto
LIBS += -L../libs -lOpePcot
}
else:win32:CONFIG(debug,debug|release) {
TARGET = WidgetCnpMetOrto
LIBS += -L../libs -lOpePcotd
}
TEMPLATE = lib

DEFINES += WIDGETCNPMETORTOTP_LIBRARY

INCLUDEPATH += ..
DESTDIR =../libs

win32:CONFIG(release, debug|release): LIBS += -L../libs -lProyectoTP
else:win32:CONFIG(debug, debug|release): LIBS += -L../libs -lProyectoTPd
else:unix:!macx: LIBS += -L../libs -lProyectoTP


SOURCES += \
    createorto.cpp \
    createmet.cpp \
    createcnps.cpp \
    ficherodatosambitopro.cpp \
    createmet.cpp \
    createorto.cpp

HEADERS +=\
        cnpmetortotp_global.h \
    createorto.h \
    createmet.h \
    createcnps.h \
    ficherodatosambitopro.h \
    createmet.h \
    createorto.h \
    widgetcnpmetortotp_global.h

unix:!symbian {
    maemunix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}


FORMS += \
    createmet.ui \
    createcnps.ui \o5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}


FORMS += \
    createmet.ui \
    createcnps.ui \
    createorto.ui \
    createmet.ui \
    createorto.ui

