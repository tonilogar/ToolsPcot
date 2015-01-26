#-------------------------------------------------
#
# Project created by QtCreator 2015-01-19T23:56:00
#
#-------------------------------------------------

QT       += widgets

TARGET = CoordinatesTP
TEMPLATE = lib

INCLUDEPATH += ..

DESTDIR =../libs

LIBS += -L../libs -lOpePcot

DEFINES += COORDINATESTP_LIBRARY

SOURCES += \
    modelocoordenadas.cpp \
    readercoordinates.cpp \
    readercoordinatesbasico.cpp \   
    tableviewcoordinates.cpp \
    dialoghelpfilecoordinates.cpp

HEADERS +=\
        coordinatestp_global.h \
    modelocoordenadas.h \
    readercoordinates.h \
    readercoordinatesbasico.h \
    tableviewcoordinates.h \
    dialoghelpfilecoordinates.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

FORMS += \
    tableviewcoordinates.ui \
    dialoghelpfilecoordinates.ui



