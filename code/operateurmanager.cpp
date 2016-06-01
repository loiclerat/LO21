#include "operateurmanager.h"
#include "exceptions.h"

operateurManager::Handler operateurManager::handler=operateurManager::Handler();


operateurManager& operateurManager::getInstance(){
    if (handler.instance==0) handler.instance=new operateurManager;
    return *handler.instance;
}

void operateurManager::libererInstance(){
    delete handler.instance;
    handler.instance=0;
}

void operateurManager::agrandissementCapacite() {
    operateur** newtab=new operateur*[(nbMax+1)*2];
    for(unsigned int i=0; i<nb; i++) newtab[i]=ops[i];
    operateur**  old=ops;
    ops=newtab;
    nbMax=(nbMax+1)*2;
    delete old;
}

// addOperateur

void operateurManager::removeoperateur(operateur& o){
    unsigned int i=0;
    while(i<nb && ops[i]!=&o) i++;
    if (i==nb) throw ComputerException("elimination d'un operateur inexistante");
    delete ops[i];
    i++;
    while(i<nb) { ops[i-1]=ops[i]; i++; }
    nb--;
}

operateurManager::~operateurManager(){
    for(unsigned int i=0; i<nb; i++) delete ops[i];
    delete[] ops;
}
