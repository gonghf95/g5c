#-------------------------------------------------
#
# Project created by QtCreator 2020-12-02T21:08:38
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = g5c
TEMPLATE = app

SOURCES += src/main.cpp \
    src/frame/App.cpp \
    src/frame/MainWindow.cpp \
    src/frame/FuncWidget.cpp \
    src/app/settings/SettingsFunc.cpp \
    src/app/test/TestFunc.cpp

HEADERS  += src/frame/App.h \
    src/frame/MainWindow.h \
    src/frame/FuncWidget.h \
    src/app/FuncId.h \
    src/app/settings/SettingsFunc.h \
    src/app/test/TestFunc.h

FORMS += \
    src/app/test/TestFunc.ui \
    src/app/settings/SettingsFunc.ui
