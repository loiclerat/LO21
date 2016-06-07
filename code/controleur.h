#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <QString>
#include <QTextStream>
#include <QObject>
#include <QDebug>

#include "pile.h"
#include "operateurmanager.h"

class Controleur {
    Pile& littAff;
    operateurManager& opeMng;
public:
    Controleur(operateurManager& o, Pile& v):littAff(v), opeMng(o){}
    void commande(const QString& c);


    operateur* estOperateur(const QString s);
    QString estLitterale(const QString s);


};

#endif // CONTROLEUR_H
