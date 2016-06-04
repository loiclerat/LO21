#include "litteralemanager.h"
#include "exceptions.h"

litteraleManager::Handler litteraleManager::handler=litteraleManager::Handler();


litteraleManager& litteraleManager::getInstance(){
    if (handler.instance==0) handler.instance=new litteraleManager;
    return *handler.instance;
}

void litteraleManager::libererInstance(){
    delete handler.instance;
    handler.instance=0;
}

void litteraleManager::agrandissementCapacite() {
    litterale** newtab=new litterale*[(nbMax+1)*2];
    for(unsigned int i=0; i<nb; i++) newtab[i]=litts[i];
    litterale**  old=litts;
    litts=newtab;
    nbMax=(nbMax+1)*2;
    delete old;
}

litterale& litteraleManager::addLitterale(littEntiere l){       //Ajout Littérale Entière
    if (nb==nbMax) agrandissementCapacite();
    litts[nb]=new littEntiere(l);
    return *litts[nb++];
}

void litteraleManager::removelitterale(litterale& l){
    unsigned int i=0;
    while(i<nb && litts[i]!=&l) i++;
    if (i==nb) throw ComputerException("elimination d'une litterale inexistante");
    delete litts[i];
    i++;
    while(i<nb) { litts[i-1]=litts[i]; i++; }
    nb--;
}

litteraleManager::~litteraleManager(){
    for(unsigned int i=0; i<nb; i++) delete litts[i];
    delete[] litts;
}
