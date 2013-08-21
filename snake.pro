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
    levels/level_1.cpp \
    rules.cpp \
    levels/level_2.cpp \
    levels/level_3.cpp \
    levels/level_4.cpp \
    levels/level_5.cpp

HEADERS  += \
    mainWindow.h \
    gameWidget.h \
    snake.h \
    headband.h \
    levels/level_1.h \
    rules.h \
    levels/level_2.h \
    levels/level_3.h \
    levels/level_4.h \
    levels/level_5.h

FORMS    += game.ui \
    headband.ui \
    rules.ui
