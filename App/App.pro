#-------------------------------------------------
#
# Project created by QtCreator 2015-09-21T23:07:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ToolsPCOT
TEMPLATE = app

INCLUDEPATH += ..

win32:CONFIG(release,debug|release){
LIBS += -L../libs -lOpePcot -lRegistroTP -lCoordinatesTP -lComponentesTP -lProyectoTP -lControlOpeTP
}
else:win32:CONFIG(debug,debug|release) {
LIBS += -L../libs -lOpePcotd -lRegistroTPd -lCoordinatesTPd -lComponentesTPd -lProyectoTPd -lControlOpeTPd
}
else:linux
{
 LIBS += -L../libs -lOpePcot -lRegistroTP -lCoordinatesTP -lComponentesTP -lProyectoTP -lControlOpeTP
}


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
