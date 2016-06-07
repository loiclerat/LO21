/**
\file pile.cpp
\date 03/06/2016
\author Loïc Lerat, Andréa Vibert, Théo Hordequin
\version 1.0
\brief  Définition des méthodes de Pile

**/

#include "pile.h"
#include "exceptions.h"

//! \brief Agrandissement de la Pile lorsque l'on dépasse la capacité actuelle
void Pile::agrandissementCapacite() {
    Item* newtab=new Item[(nbMax+1)*2];
    for(unsigned int i=0; i<nb; i++) newtab[i]=items[i];
    Item*  old=items;
    items=newtab;
    nbMax=(nbMax+1)*2;
    delete[] old;
}

//! \brief Ajouter une littérale au sommet de la pile
void Pile::push(litterale& l){
    modificationEtat();
    if (nb==nbMax) agrandissementCapacite();
    litterale* littSimplif=l.simplifier();
    items[nb].setLitterale(*littSimplif);
    if(&l!=littSimplif)// si on a procédé à une simplification, on supprime la variable initiale (par exemple : 3$0 donne un entier 3)
        delete &l;
    nb++;
}

//! \brief Dépiler la littérale au sommet de la pile
void Pile::pop(){
    nb--;
    items[nb].raz();
    modificationEtat();
}

//! \brief Destructeur
Pile::~Pile(){
    delete[] items;
}

//! \brief Retourne une référence vers la littérale au sommet de la Pile
litterale& Pile::top() const {

    if (nb==0) throw ComputerException("aucune litterale sur la pile");
    return items[nb-1].getLitterale();
}
