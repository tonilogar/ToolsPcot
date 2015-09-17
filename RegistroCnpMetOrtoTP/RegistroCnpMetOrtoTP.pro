QT       += widgets

win32:CONFIG(release,debug|release){
TARGET = RegistroCnpMetOrtoTP
LIBS += -L../libs -lOpePcot
}
else:win32:CONFIG(debug,debug|release) {
TARGET = RegistroCnpMetOrtoTP
LIBS += -L../libs -lOpePcotd
}
TEMPLATE = lib


DEFINES += REGISTROCNPMETORTOTP_LIBRARY

INCLUDEPATH += ..
DESTDIR =../libs

win32:CONFIG(release, debug|release): LIBS += -L../libs -lProyectoTP
else:win32:CONFIG(debug, debug|release): LIBS += -L../libs -lProyectoTPd
else:unix:!macx: LIBS += -L../libs -lProyectoTP

SOURCES += \
    registrocreatecnps.cpp \
    registrocreatemet.cpp \
    registrocreateorto.cpp \
    ficherodatosambitopro.cpp

HEADERS +=\
        registrocnpmetortotp_global.h \
    registrocreatecnps.h \
    registrocreatemet.h \
    registrocreateorto.h \
    ficherodatosambitopro.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

unix:!symbian {
    maemunix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

FORMS +=

RESOURCES +=

FORMS +=

