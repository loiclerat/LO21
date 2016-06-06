#ifndef MEMENTO_H
#define MEMENTO_H

#include "pile.h"
#include <vector>


class Memento{
    Pile etat;

public:

    Memento(Pile p):etat(p){}
    Pile getState();
};



class Originator {
   Pile etat;

public:

   void setEtat(Pile etat){ this.etat = etat; }

   Pile getEtat(){ return etat; }

   Memento saveetatToMemento(){ return new Memento(etat); }

   void getetatFromMemento(Memento Memento){ etat = Memento.getetat(); }
};


class CareTaker {


public:


};


#endif // MEMENTO_H
