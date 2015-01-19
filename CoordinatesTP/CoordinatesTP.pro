#-------------------------------------------------
#
# Project created by QtCreator 2015-01-19T23:56:00
#
#-------------------------------------------------

QT       += widgets

TARGET = CoordinatesTP
TEMPLATE = lib

DEFINES += COORDINATESTP_LIBRARY

SOURCES += \
    tableviewcoordinates.cpp \
    readercoordinatesbasico.cpp \
    readercoordinates.cpp \
    modelocoordenadas.cpp

HEADERS +=\
        coordinatestp_global.h \
    tableviewcoordinates.h \
    readercoordinatesbasico.h \
    readercoordinates.h \
    modelocoordenadas.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

FORMS += \
    tableviewcoordinates.ui

RESOURCES += \
    recursos.qrc
