
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
    add.cpp \
    operateurmanager.cpp \
    mul.cpp \
    sous.cpp \
    divs.cpp \
    divent.cpp \
    mod.cpp \
    neg.cpp \
    num.cpp \
    den.cpp \
    dollar.cpp \
    opre.cpp \
    opim.cpp \
    opegal.cpp \
    opdiff.cpp \
    opegalinf.cpp \
    opegalsup.cpp \
    opsup.cpp \
    opinf.cpp \
    opand.cpp \
    opor.cpp \
    opnot.cpp \
    opeval.cpp \
    memento.cpp \
    opift.cpp \
    opdup.cpp \
    parametres.cpp \
    litterale.cpp

HEADERS += \
    litterale.h \
    operateur_numerique.h \
    operateur.h \
    controleur.h \
    exceptions.h \
    item.h \
    pile.h \
    add.h \
    num.h \
    operateurmanager.h \
    mul.h \
    sous.h \
    divs.h \
    divent.h \
    mod.h \
    neg.h \
    den.h \
    dollar.h \
    opre.h \
    opim.h \
    opegal.h \
    operateur_logique.h \
    opdiff.h \
    opegalinf.h \
    opegalsup.h \
    opsup.h \
    opinf.h \
    opand.h \
    opor.h \
    opnot.h \
    memento.h \
    operande.h \
    opeval.h \
    qcomputer.h \
    opift.h \
    operateur_conditionnel.h \
    operateur_pile.h \
    opdup.h \
    parametres.h
