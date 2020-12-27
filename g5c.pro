#-------------------------------------------------
#
# Project created by QtCreator 2020-12-02T21:08:38
#
#-------------------------------------------------

QT       += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++11

TARGET = g5c
TEMPLATE = app

SOURCES += src/main.cpp \
    src/frame/Application.cpp \
    src/frame/FuncWidgetController.cpp \
    src/frame/LeftBar.cpp \
    src/frame/MainWindow.cpp \
    src/frame/FuncWidget.cpp \
    src/frame/WorkWidget.cpp \
    src/db/DbManager.cpp \
    src/entity/User.cpp \
    src/net/NetService.cpp \
    src/app/default/DefaultFunc.cpp \
    src/app/chat/ChatFunc.cpp \
    src/app/settings/SettingsFunc.cpp \
    src/app/test/TestFunc.cpp \
    src/common/Logger.cpp \
    src/widget/ChatList.cpp \
    src/widget/ChatListItemDelegate.cpp \
    src/widget/ScrollBar.cpp

HEADERS  += src/frame/Application.h \
    src/entity/entity.h \
    src/frame/FuncWidgetController.h \
    src/frame/LeftBar.h \
    src/frame/MainWindow.h \
    src/frame/FuncWidget.h \
    src/frame/WorkWidget.h \
    src/common/Common.h \
    src/db/DbManager.h \
    src/entity/User.h \
    src/net/NetService.h \
    src/app/FuncId.h \
    src/app/default/DefaultFunc.h \
    src/app/chat/ChatFunc.h \
    src/app/settings/SettingsFunc.h \
    src/app/test/TestFunc.h \
    src/common/Logger.h \
    src/widget/ChatList.h \
    src/widget/ChatListItemDelegate.h \
    src/widget/ScrollBar.h

FORMS += \
    src/app/chat/ChatFunc.ui \
    src/app/default/DefaultFunc.ui \
    src/app/test/TestFunc.ui \
    src/app/settings/SettingsFunc.ui \
    src/frame/LeftBar.ui

RESOURCES += \
    resource.qrc
