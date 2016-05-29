
QT += core
QT -= gui
QT       += core gui widgets
CONFIG += c++11

TARGET = code
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    main.cpp \
    littententiere.cpp \
    littreelle.cpp \
    computer.cpp \
    littrat.cpp \
    qcomputer.cpp

HEADERS += \
    litterale.h \
    littentiere.h \
    littnumerique.h \
    littreelle.h \
    computer.h \
    littrat.h \
    operateur_numerique.h \
    operateur.h \
    qcomputer.h
