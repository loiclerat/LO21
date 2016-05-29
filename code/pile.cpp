#include "pile.h"
#include "exceptions.h"

void Pile::agrandissementCapacite() {
    Item* newtab=new Item[(nbMax+1)*2];
    for(unsigned int i=0; i<nb; i++) newtab[i]=items[i];
    Item*  old=items;
    items=newtab;
    nbMax=(nbMax+1)*2;
    delete[] old;
}

void Pile::push(litterale& l){
    if (nb==nbMax) agrandissementCapacite();
    items[nb].setLitterale(l);
    nb++;
    modificationEtat();
}

void Pile::pop(){
    nb--;
    items[nb].raz();
    modificationEtat();
}

void Pile::affiche(QTextStream& f) const{

    // Affichage de la pile

}


Pile::~Pile(){
    delete[] items;
}

litterale& Pile::top() const {

    if (nb==0) throw ComputerException("aucune litterale sur la pile");
    return items[nb-1].getLitterale();
}
