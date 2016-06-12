
QT += core
QT -= gui
QT += core gui widgets
QT += multimedia

CONFIG += c++11

TARGET = code
CONFIG += console
CONFIG -= app_bundle
QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter
QMAKE_CXXFLAGS_WARN_ON += -Wno-return-type

TEMPLATE = app

SOURCES += \
    main.cpp \
    qcomputer.cpp \
    controleur.cpp \
    item.cpp \
    pile.cpp \
    operateurmanager.cpp \
    memento.cpp \
    parametres.cpp \
    litterale.cpp \
    operateur.cpp

HEADERS += \
    litterale.h \
    operateur.h \
    controleur.h \
    exceptions.h \
    item.h \
    pile.h \
    operateurmanager.h \
    memento.h \
    operande.h \
    qcomputer.h \
    parametres.h \
    operande.h
