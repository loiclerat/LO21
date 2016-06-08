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




operateurManager::operateurManager():ops(new operateur*[12]),nb(12){

    //! \brief Op�rateur d'addition
    add* addition=new add();
    //! \brief Op�rateur de soustraction
    sous* soustraction= new sous();
    //! \brief Op�rateur de multiplication
    mul* multiplication= new mul();
    //! \brief Op�rateur de division
    divs* division= new divs();
    //! \brief Op�rateur de cr�ation de complexe
    dollar* complexe= new dollar();
    //! \brief Op�rateur pour obtenir le negatif
    neg* negatif= new neg();
    //! \brief Op�rateur pour obtenir le resultat du test ==
    opegal* egalite= new opegal();
    //! \brief Op�rateur pour obtenir le resultat du test !=
    opdiff* difference= new opdiff();
    //! \brief Op�rateur pour obtenir resultat du test <=
    opegalinf* inferouegal= new opegalinf();
    //! \brief Op�rateur pour obtenir le resultat du test >=
    opegalsup* superouegal= new opegalsup();
    //! \brief Op�rateur pour obtenir le resultat du test >=
    opinf* inferiorite= new opinf();
    //! \brief Op�rateur pour obtenir le resultat du test >=
    opsup* superiorite= new opsup();

    ops[0] = addition;
    ops[1] = soustraction;
    ops[2] = multiplication;
    ops[3] = division;
    ops[4] = complexe;
    ops[5] = negatif; //ne marche pas il faut des litt atome pour le faire
    ops[6] = egalite;
    ops[7] = difference;
    ops[8] = superiorite;
    ops[9] = inferiorite;
    ops[10] = superouegal;
    ops[11] = inferouegal;
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
