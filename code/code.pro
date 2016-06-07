
QT += core
QT -= gui
QT += core gui widgets
QT += multimedia

CONFIG += c++11

TARGET = code
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    main.cpp \
    littentiere.cpp \
    littreelle.cpp \
    littrat.cpp \
    qcomputer.cpp \
    controleur.cpp \
    item.cpp \
    littcomplexe.cpp \
    litteralemanager.cpp \
    pile.cpp \
    littatome.cpp \
    alitt.cpp \
    aoperateur.cpp \
    add.cpp \
    operateurmanager.cpp \
    mul.cpp \
    littnumber.cpp \
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
    littprogramme.cpp
    qcomputer.cpp

HEADERS += \
    litterale.h \
    littentiere.h \
    littnumerique.h \
    littreelle.h \
    littrat.h \
    operateur_numerique.h \
    operateur.h \
    qcomputer.h \
    controleur.h \
    exceptions.h \
    item.h \
    littcomplexe.h \
    litteralemanager.h \
    pile.h \
    littatome.h \
    add.h \
    alitt.h \
    aoperateur.h \
    num.h \
    operateurmanager.h \
    mul.h \
    littnumber.h \
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
    littprogramme.h
    qcomputer.h
