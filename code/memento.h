#ifndef MEMENTO_H
#define MEMENTO_H

#include "pile.h"
#include <vector>


class Memento{
    Pile* etat;

public:
    Memento(Pile& p){ etat = new Pile(p); }

    Pile& getEtat() const {return *etat;}

    ~Memento(){delete etat;}

};


class CareTaker {
    vector<Memento*> historique;

public:

    void add(Memento& etat, unsigned int i){
        if (i<historique.size()){
            historique[i]=&etat;
            qDebug()<<"bou";
        }
        else historique.push_back(&etat);
    }

    Memento& get(unsigned int i) const {return *historique[i];}

    unsigned int taille() const { return historique.size(); }

    void pop(){ historique.pop_back();}

};


#endif // MEMENTO_H
