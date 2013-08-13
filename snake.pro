#-------------------------------------------------
#
# Project created by QtCreator 2013-08-09T17:36:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = snake
TEMPLATE = app


SOURCES += main.cpp \
    mainWindow.cpp \
    gameWidget.cpp \
    headband.cpp \
    levels/level_1.cpp

HEADERS  += \
    mainWindow.h \
    gameWidget.h \
    snake.h \
    headband.h \
    levels/level_1.h

FORMS    += game.ui \
    headband.ui
