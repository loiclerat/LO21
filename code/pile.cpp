/**
\file pile.cpp
\date 03/06/2016
\author Loïc Lerat, Andréa Vibert, Théo Hordequin
\version 1.0
\brief  Définition des méthodes de Pile

**/

#include "pile.h"
#include "exceptions.h"
#include "littentiere.h"
#include "littatome.h"
#include "littcomplexe.h"
#include "littrat.h"
#include "littreelle.h"
#include <typeinfo>







Pile::Pile(Pile& p):QObject(), nb(p.taille()), nbMax(p.getCapacite()), nbAffiche(p.getNbItemsToAffiche()), items(new Item[p.nbMax]) {
    unsigned int i=0;
    for (iterator it = p.begin_inverse() ; it != p.end_inverse()  ; --it){
            litterale& a = (*it);
            littEntiere* ent = dynamic_cast<littEntiere*>(&a);
           // littrat* rat = dynamic_cast<littrat*>(&a);
            //littReelle* reel = dynamic_cast<littReelle*>(&a);
            //littcomplexe* comp = dynamic_cast<littcomplexe*>(&a);
            //littatome* atm = dynamic_cast<littatome*>(&a);

            if (ent != 0){

                littEntiere* l = new littEntiere(*ent);
                items[i].setLitterale(*l);
            }
            /*else if (rat != 0){
                littrat* l = new littrat(*rat);
                items[i].setLitterale(*l);
            }
            else if (reel != 0){
                littReelle* l = new littReelle(*reel);
                items[i].setLitterale(*l);
            }
            /*else if (comp != 0){
                littcomplexe* l = new littcomplexe(*comp);
                items[i].setLitterale(*l);
            }*/
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
    if (nb==nbMax) agrandissementCapacite();
    litterale* littSimplif=l.simplifier();
    items[nb].setLitterale(*littSimplif);
    if(&l!=littSimplif)// si on a procédé à une simplification, on supprime la variable initiale (par exemple : 3$0 donne un entier 3)
        delete &l;
    nb++;
    modificationEtat();
}

//! \brief Dépiler la littérale au sommet de la pile
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

//! \brief Retourne une référence vers la littérale au sommet de la Pile
litterale& Pile::top() const {

    if (nb==0) throw ComputerException("aucune litterale sur la pile");
    return items[nb-1].getLitterale();
}
