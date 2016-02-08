#-------------------------------------------------
#
# Project created by QtCreator 2016-02-08T23:08:12
#
#-------------------------------------------------

QT       += widgets

win32:CONFIG(release,debug|release){
TARGET = WidgetProyectoTP
LIBS += -L../libs -lProyectoTP
}
else:win32:CONFIG(debug,debug|release) {
TARGET = WidgetProyectoTPd
LIBS += -L../libs -lProyectoTPd
}

TARGET = WidgetProyectoTP
TEMPLATE = lib

INCLUDEPATH += ..
DESTDIR =../libs

DEFINES += WIDGETPROYECTOTP_LIBRARY

SOURCES += \
    newprojectdialog.cpp \
    calendardialog.cpp

HEADERS +=\
        widgetproyectotp_global.h \
    newprojectdialog.h \
    calendardialog.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    newprojectdialog.ui \
    calendardialog.ui
