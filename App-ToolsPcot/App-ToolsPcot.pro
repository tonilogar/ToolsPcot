#-------------------------------------------------
#
# Project created by QtCreator 2015-01-29T22:31:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ToolsPcot
TEMPLATE = app

INCLUDEPATH += ..


SOURCES += \       
    dialogprogresoope.cpp \
    dialogopreferencias.cpp \
    mainwindow.cpp \
    main.cpp

HEADERS  += \
    dialogprogresoope.h \
    dialogopreferencias.h \
    mainwindow.h

FORMS    += \
    dialogprogresoope.ui \
    dialogopreferencias.ui \
    mainwindow.ui



win32:CONFIG(release, debug|release): LIBS += -L../libs -lCnpMetOrtoTP
else:win32:CONFIG(debug, debug|release): LIBS += -L../libs -lCnpMetOrtoTPd
else:unix:!macx: LIBS += -L../libs -lCnpMetOrtoTP

DEPENDPATH += ../libs

win32:CONFIG(release, debug|release): LIBS += -L../libs -lComponentesTP
else:win32:CONFIG(debug, debug|release): LIBS += -L../libs -lComponentesTPd
else:unix:!macx: LIBS += -L../libs -lComponentesTP

win32:CONFIG(release, debug|release): LIBS += -L../libs -lControlOpeTP
else:win32:CONFIG(debug, debug|release): LIBS += -L../libs -lControlOpeTPd
else:unix:!macx: LIBS += -L../libs -lControlOpeTP

win32:CONFIG(release, debug|release): LIBS += -L../libs -lOpePcot
else:win32:CONFIG(debug, debug|release): LIBS += -L../libs -lOpePcotd
else:unix:!macx: LIBS += -L../libs -lOpePcot

win32:CONFIG(release, debug|release): LIBS += -L../libs -lCoordinatesTP
else:win32:CONFIG(debug, debug|release): LIBS += -L../libs -lCoordinatesTPd
else:unix:!macx: LIBS += -L../libs -lCoordinatesTP


