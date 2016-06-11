
QT += core
QT -= gui
QT += core gui widgets
QT += multimedia

CONFIG += c++11

TARGET = code
CONFIG += console
CONFIG -= app_bundle
QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter

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
    pile.cpp \
    littatome.cpp \
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
    littprogramme.cpp \
    littnumerique.cpp \
    opeval.cpp \
    atomemanager.cpp \
    memento.cpp \
    opift.cpp

HEADERS += \
    litterale.h \
    littentiere.h \
    littnumerique.h \
    littreelle.h \
    littrat.h \
    operateur_numerique.h \
    operateur.h \
    controleur.h \
    exceptions.h \
    item.h \
    littcomplexe.h \
    pile.h \
    add.h \
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
    littprogramme.h \
    memento.h \
    operande.h \
    opeval.h \
    atomemanager.h \
    qcomputer.h \
    opift.h \
    operateur_conditionnel.h
