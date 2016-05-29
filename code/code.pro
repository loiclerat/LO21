
QT += core
QT -= gui
QT += core gui widgets

CONFIG += c++11

TARGET = code
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    main.cpp \
    littententiere.cpp \
    littreelle.cpp

HEADERS += \
    litterale.h \
    littentiere.h \
    littnumerique.h \
    littreelle.h
