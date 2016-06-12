/**
\file pile.cpp
\date 03/06/2016
\author Loïc Lerat, Andr�a Vibert, Th�o Hordequin
\version 1.0
\brief  D�finition des m�thodes de Pile

**/

#include "pile.h"
#include "exceptions.h"
#include "litterale.h"
#include "controleur.h"
#include <typeinfo>

unsigned int Pile::nbAffiche = 5;


Pile::Pile(Pile& p):QObject(), nb(p.taille()), nbMax(p.getCapacite()), items(new Item[p.nbMax]) {
    unsigned int i=0;
    for (iterator it = p.begin_inverse() ; it != p.end_inverse()  ; --it){
        items[i].setLitterale(*it);
        i++;
        }
}


Pile& Pile::operator=(Pile& p){
    if (this==&p) return *this;

    nb = p.taille();
    nbMax = p.getCapacite();
    message = p.getMessage();
    nbAffiche = p.getNbItemsToAffiche();
    items = p.getItems();

    return *this;
}



//! \brief Agrandissement de la Pile lorsque l'on d�passe la capacit� actuelle
void Pile::agrandissementCapacite() {
    Item* newtab=new Item[(nbMax+1)*2];
    for(unsigned int i=0; i<nb; i++) newtab[i]=items[i];
    Item*  old=items;
    items=newtab;
    nbMax=(nbMax+1)*2;
    delete[] old;
}

//! \brief Ajouter une litt�rale au sommet de la pile
void Pile::push(litterale& l){
    if (nb==nbMax) agrandissementCapacite();
    items[nb].setLitterale(l);
    nb++;
    modificationEtat();
}

//! \brief D�piler la litt�rale au sommet de la pile
void Pile::pop(){
    nb--;
    items[nb].raz();
    modificationEtat();
}

//! \brief Destructeur
Pile::~Pile(){
    for (unsigned int i=0 ; i<nb ; i++)
        delete &(items[i].getLitterale());
    delete[] items;
}

//! \brief Retourne une r�f�rence vers la litt�rale au sommet de la Pile
litterale& Pile::top() const {

    if (nb==0) throw ComputerException("aucune litterale sur la pile");
    return items[nb-1].getLitterale();
}

