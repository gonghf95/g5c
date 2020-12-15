#-------------------------------------------------
#
# Project created by QtCreator 2020-12-02T21:08:38
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++11

TARGET = g5c
TEMPLATE = app

SOURCES += src/main.cpp \
    src/frame/Application.cpp \
    src/frame/LeftBar.cpp \
    src/frame/MainWindow.cpp \
    src/frame/FuncWidget.cpp \
    src/frame/WorkWidget.cpp \
    src/app/default/DefaultFunc.cpp \
    src/app/settings/SettingsFunc.cpp \
    src/app/test/TestFunc.cpp \
    src/public/Logger.cpp \
    src/widget/ChatList.cpp \
    src/widget/ChatListItemDelegate.cpp

HEADERS  += src/frame/Application.h \
    src/frame/LeftBar.h \
    src/frame/MainWindow.h \
    src/frame/FuncWidget.h \
    src/frame/WorkWidget.h \
    src/public/Common.h \
    src/app/FuncId.h \
    src/app/default/DefaultFunc.h \
    src/app/settings/SettingsFunc.h \
    src/app/test/TestFunc.h \
    src/public/Logger.h \
    src/widget/ChatList.h \
    src/widget/ChatListItemDelegate.h

FORMS += \
    src/app/test/TestFunc.ui \
    src/app/settings/SettingsFunc.ui \
    src/frame/LeftBar.ui

RESOURCES += \
    resource.qrc
