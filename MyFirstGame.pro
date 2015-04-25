#-------------------------------------------------
#
# Project created by QtCreator 2015-04-24T17:20:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyFirstGame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Enemy.cpp \
    Bullet.cpp \
    Player.cpp \
    Game.cpp

HEADERS  += mainwindow.h \
    Enemy.h \
    Bullet.h \
    Player.h \
    Game.h

FORMS    += mainwindow.ui
