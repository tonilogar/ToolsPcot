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
LIBS += -L../libs -lAmbitoTP -lOpePcot -lRegistroTP -lCoordinatesTP -lComponentesTP -lProyectoTP -lControlOpeTP -lWidgetProyectoTP -lWidgetCoordinatesTP -lWidgetRegistroTP
}
else:win32:CONFIG(debug,debug|release) {
LIBS += -L../libs -lAmbitoTPd -lOpePcotd -lRegistroTPd -lCoordinatesTPd -lComponentesTPd -lProyectoTPd -lControlOpeTPd -lWidgetProyectoTPd -lWidgetCoordinatesTPd -lWidgetRegistroTPd
}
!win32
{
 LIBS += -L../libs -lAmbitoTP -lOpePcot -lRegistroTP -lCoordinatesTP -lComponentesTP -lProyectoTP -lControlOpeTP -lWidgetProyectoTP -lWidgetCoordinatesTP -lWidgetRegistroTP
}


SOURCES += main.cpp\
        mainwindow.cpp \
    preferenciasavanzadasdialog.cpp \
    alertfilejson.cpp \
    editorambitodialog.cpp \
    ambitowidget.cpp

HEADERS  += mainwindow.h \
    preferenciasavanzadasdialog.h \
    alertfilejson.h \
    editorambitodialog.h \
    ambitowidget.h

FORMS    += mainwindow.ui \
    preferenciasavanzadasdialog.ui \
    alertfilejson.ui \
    editorambitodialog.ui \
    ambitowidget.ui
