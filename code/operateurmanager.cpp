/**
\file operateurmanager.cpp
\date 03/06/2016
\author Loïc Lerat, Andréa Vibert, Théo Hordequin
\version 1.0
\brief  Definition des méthodes de la classe operateurManager

**/


#include "operateurmanager.h"
#include "exceptions.h"


// Initialisation de tous les opérateurs (attributs statiques)




operateurManager::operateurManager():ops(new operateur*[2]),nb(2){

    //! \brief Op�rateur d'addition
    add* addition=new add();
    //! \brief Op�rateur de soustraction
    sous* soustraction= new sous();

    ops[0] = addition;
    ops[1] = soustraction;
}


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


//! \brief Destructeur
operateurManager::~operateurManager(){
    for(unsigned int i=0; i<nb; i++) delete ops[i];
    delete[] ops;
}
