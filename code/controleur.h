#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <QString>
#include <QTextStream>
#include <QObject>
#include <QDebug>
#include <QMap>
#include <QList>
#include "operateurmanager.h"
#include "memento.h"
#include "operande.h"

class Controleur {
    static Controleur* cinstance;
    Pile& littAff;
    operateurManager& opeMng;
    CareTaker careTaker;

    unsigned int history_index;

    // QMAP littAtome :
    QMap<QString, operateur*> mapAtome;

public:
    Controleur(operateurManager& o, Pile& v);
    Controleur(Controleur& c):littAff(c.littAff), opeMng(c.opeMng), careTaker(), history_index(0) {}
    ~Controleur() {}

public:



    //! \brief Récupérer l'instance unique d'operateurManager
    static Controleur& getInstance(Pile *pile = 0);
    //! \brief Libération de l'instance
    static void libererInstance();


    void commande(const QString& c);

    operateur* estOperateur(const QString s);
    QString estLitterale(const QString s);
    QString estLitteraleAtome(const QString s);

    Pile& getterPile(){
        return littAff;
    }

    // FABRIQUE :

    QList<Operande*> FactoryMethod(QString str);
    Operande* CreateConcrete(QString str);

    // MEMENTO :

    Memento& saveEtatToMemento(Pile& p){ return *(new Memento(p));}
    void getEtatFromMemento(Memento& m){ littAff = m.getEtat(); }

    void save();
    void loadPrecedent();
    void loadSuivant();


};

#endif // CONTROLEUR_H
