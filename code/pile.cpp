/**
\file pile.cpp
\date 03/06/2016
\author LoÃ¯c Lerat, AndrÃ©a Vibert, ThÃ©o Hordequin
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

//! \brief Ajouter une littÃ©rale au sommet de la pile
void Pile::push(litterale& l){
    if (nb==nbMax) agrandissementCapacite();
    items[nb].setLitterale(l);
    nb++;
    modificationEtat();
}

//! \brief Dépiler la littérale au sommet de la pile
void Pile::pop(){
    nb--;
    items[nb].raz();
    modificationEtat();
}

//! \brief Afficher la pile
//! \n L'affichage s'effectue dans un QTextStream selon le nombre d'éléments à afficher
void Pile::affiche(QTextStream& f) const{

    // Affichage de la pile

}

//! \brief Destructeur
Pile::~Pile(){
    delete[] items;
}

//! \brief Retourne une rÃ©fÃ©rence vers la littÃ©rale au sommet de la Pile
litterale& Pile::top() const {

    if (nb==0) throw ComputerException("aucune litterale sur la pile");
    return items[nb-1].getLitterale();
}
