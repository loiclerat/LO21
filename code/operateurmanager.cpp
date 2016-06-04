/**
\file operateurmanager.cpp
\date 03/06/2016
\author Loïc Lerat, Andréa Vibert, Théo Hordequin
\version 1.0
\brief  Definition des méthodes de la classe operateurManager

**/


#include "operateurmanager.h"
#include "exceptions.h"

//! \brief Initialisation de l'attribut statique handler
operateurManager::Handler operateurManager::handler=operateurManager::Handler();


//! \brief Récupérer l'instance unique d'operateurManager
operateurManager& operateurManager::getInstance(){
    if (handler.instance==0) handler.instance=new operateurManager;
    return *handler.instance;
}

//! \brief Libération de l'instance
void operateurManager::libererInstance(){
    delete handler.instance;
    handler.instance=0;
}

//! \brief Agrandissement de la liste lorsque l'on dépasse la capacité actuelle
void operateurManager::agrandissementCapacite() {
    operateur** newtab=new operateur*[(nbMax+1)*2];
    for(unsigned int i=0; i<nb; i++) newtab[i]=ops[i];
    operateur**  old=ops;
    ops=newtab;
    nbMax=(nbMax+1)*2;
    delete old;
}


//! \todo Ajout de la méthode addOperateur


//! \brief Supprimer un opérateur de la liste
void operateurManager::removeoperateur(operateur& o){
    unsigned int i=0;
    while(i<nb && ops[i]!=&o) i++;
    if (i==nb) throw ComputerException("elimination d'un operateur inexistante");
    delete ops[i];
    i++;
    while(i<nb) { ops[i-1]=ops[i]; i++; }
    nb--;
}

//! \brief Destructeur
operateurManager::~operateurManager(){
    for(unsigned int i=0; i<nb; i++) delete ops[i];
    delete[] ops;
}
