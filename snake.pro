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
    gameWidget.cpp

HEADERS  += \
    mainWindow.h \
    gameWidget.h \
    snake.h

FORMS    += game.ui