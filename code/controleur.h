#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <QString>
#include <QTextStream>
#include <QObject>
#include <QDebug>

#include "pile.h"
#include "operateurmanager.h"
#include "memento.h"

class Controleur {
    Pile& littAff;
    operateurManager& opeMng;
    CareTaker careTaker;

    unsigned int history_index;

public:
    Controleur(operateurManager& o, Pile& v):littAff(v), opeMng(o), careTaker(), history_index(0){
        save();
    }
    void commande(const QString& c);

    operateur* estOperateur(const QString s);
    QString estLitterale(const QString s);
    QString estLitteraleAtome(const QString s);


    // MEMENTO :

    Memento& saveEtatToMemento(Pile& p){ return *(new Memento(p));}
    void getEtatFromMemento(Memento& m){ littAff = m.getEtat(); }

    void save();
    void loadPrecedent();
    void loadSuivant();


};

#endif // CONTROLEUR_H
