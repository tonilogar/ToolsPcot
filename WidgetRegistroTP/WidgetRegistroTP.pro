#-------------------------------------------------
#
# Project created by QtCreator 2016-03-24T22:37:12
#
#-------------------------------------------------

QT       += widgets

unix {
    TARGET = WidgetRegistroTP
LIBS += -L../libs -lProyectoTP -lRegistroTP
}
win32:CONFIG(release,debug|release){
TARGET = WidgetRegistroTP
LIBS += -L../libs -lProyectoTP -lRegistroTP
}
else:win32:CONFIG(debug,debug|release) {
TARGET = WidgetRegistroTPd
LIBS += -L../libs -lProyectoTPd -lRegistroTPd
}

TEMPLATE = lib

INCLUDEPATH += ..
DESTDIR =../libs

DEFINES += WIDGETREGISTROTP_LIBRARY

SOURCES += \
    widgetregistro.cpp \
    widgetcnp.cpp

HEADERS +=\
        widgetregistrotp_global.h \
    widgetregistro.h \
    widgetcnp.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    widgetcnp.ui

