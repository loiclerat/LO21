QT += widgets
QT += core
QT -= gui

CONFIG += c++11

TARGET = IHM_Qt
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    qcomputer.cpp \
    main.cpp

HEADERS += \
    qcomputer.h \
