#-------------------------------------------------
#
# Project created by QtCreator 2012-01-27T05:31:42
#
#-------------------------------------------------

QT       += core gui

TARGET = Vortex
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    jshint.cpp \
    jsedit.cpp

HEADERS  += mainwindow.h \
    jshint.h \
    jsedit.h

FORMS    += mainwindow.ui

LIBS += -lqtermwidget -lqjson

OTHER_FILES +=

RESOURCES += \
    images.qrc
