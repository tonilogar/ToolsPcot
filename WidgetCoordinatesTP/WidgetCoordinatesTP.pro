#-------------------------------------------------
#
# Project created by QtCreator 2016-02-08T23:48:37
#
#-------------------------------------------------

QT       += widgets

win32:CONFIG(release,debug|release){
TARGET = WidgetCoordinatesTP
LIBS += -L../libs -lCoordinatesTP
}
else:win32:CONFIG(debug,debug|release) {
TARGET = WidgetCoordinatesTPd
LIBS += -L../libs -lCoordinatesTPd
}
else:!win32
{
TARGET = WidgetCoordinatesTP
LIBS += -L../libs -lCoordinatesTP
}

TEMPLATE = lib

DEFINES += WIDGETCOORDINATESTP_LIBRARY

INCLUDEPATH+=..
DESTDIR=../libs

SOURCES += \
    dialoghelpfilecoordinates.cpp \
    widgetcoordinates.cpp

HEADERS +=\
        widgetcoordinatestp_global.h \
    dialoghelpfilecoordinates.h \
    widgetcoordinates.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    dialoghelpfilecoordinates.ui \
    widgetcoordinates.ui
