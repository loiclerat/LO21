#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <QString>
#include <QTextStream>
#include <QObject>
#include <QDebug>

#include "pile.h"
#include "litteralemanager.h"

class Controleur {
    litteraleManager& littMng;
    Pile& littAff;
public:
    Controleur(litteraleManager& m, Pile& v):littMng(m), littAff(v){}
    void commande(const QString& c);

};

#endif // CONTROLEUR_H
