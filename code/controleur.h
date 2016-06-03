#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <QString>
#include <QTextStream>
#include <QObject>
#include <QDebug>

#include "pile.h"
#include "litteralemanager.h"
#include "operateurmanager.h"

class Controleur {
    litteraleManager& littMng;
    Pile& littAff;
    operateurManager& opeMng;
public:
    Controleur(litteraleManager& m, operateurManager& o, Pile& v):littMng(m), littAff(v), opeMng(o){}
    void commande(const QString& c);


    operateur* estOperateur(const QString s);
    QString estLitterale(const QString s);


};

#endif // CONTROLEUR_H
