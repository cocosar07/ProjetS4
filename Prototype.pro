#-------------------------------------------------
#
# Project created by QtCreator 2016-03-02T19:54:11
#
#-------------------------------------------------

QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Prototype
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    connectionthread.cpp \
    Macrocommande.cpp \
    Microcommande.cpp \
    stringFunctions.cpp \
    Test.cpp

HEADERS  += mainwindow.h \
    connectionthread.h \
    Macrocommande.hpp \
    Microcommande.hpp \
    stringFunctions.hpp \
    Test.hpp

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$quote(C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/Lib/) -lshell32
else:win32:CONFIG(debug, debug|release): LIBS += -L$$quote(C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/Lib/) -lshell32

INCLUDEPATH += $$quote(C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/Include)
DEPENDPATH += $$quote(C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/Include)
