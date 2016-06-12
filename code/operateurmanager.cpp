/**
\file operateurmanager.cpp
\date 03/06/2016
\author Loéc Lerat, Andréa Vibert, Théo Hordequin
\version 1.0
\brief  Definition des méthodes de la classe operateurManager
**/


#include "operateurmanager.h"

// Initialisation de tous les opérateurs (attributs statiques)

unsigned int operateurManager::nb=24;

operateurManager::operateurManager():ops(new operateur*[nb]){

    //! \brief Opé½rateur d'addition
    add* addition=new add();
    //! \brief Opé½rateur de soustraction
    sous* soustraction= new sous();
    //! \brief Opé½rateur de multiplication
    mul* multiplication= new mul();
    //! \brief Opé½rateur de division
    divs* division= new divs();
    //! \brief Opé½rateur de création de complexe
    dollar* complexe= new dollar();
    //! \brief Opé½rateur pour obtenir le negatif
    neg* negatif= new neg();
    //! \brief Opé½rateur pour obtenir le resultat du test ==
    opegal* egalite= new opegal();
    //! \brief Opé½rateur pour obtenir le resultat du test !=
    opdiff* difference= new opdiff();
    //! \brief Opé½rateur pour obtenir resultat du test <=
    opegalinf* inferouegal= new opegalinf();
    //! \brief Opé½rateur pour obtenir le resultat du test >=
    opegalsup* superouegal= new opegalsup();
    //! \brief Opé½rateur pour obtenir le resultat du test >=
    opinf* inferiorite= new opinf();
    //! \brief Opé½rateur pour obtenir le resultat du test >=
    opsup* superiorite= new opsup();

    //! \brief Opérateur pour obtenir le resultat de la division entière
    divent* diventiere= new divent();
    //! \brief Opérateur pour obtenir le dénominateur d'un rationnel
    den* denominateur= new den();
    //! \brief Opérateur pour obtenir le numérateur d'un rationnel
    num* numerateur= new num();
    //! \brief Opérateur pour obtenir la partie réelle d'un complexe
    opre* partieReelle= new opre();
    //! \brief Opérateur pour obtenir la partie imaginaire d'un complexe
    opim* partieImaginaire= new opim();
    //! \brief Opérateur pour obtenir le résultat d'un ET
    opand* et= new opand();
    //! \brief Opérateur pour obtenir le résultat d'un OU
    opor* ou= new opor();
    //! \brief Opérateur pour obtenir le résultat d'un NOT
    opnot* non= new opnot();
    //! \brief Opérateur pour obtenir le résultat d'un EVAL
    opeval* eval= new opeval();
    //! \brief Opérateur pour obtenir le résultat d'un IFT
    opIft* ift= new opIft();
    //! \brief Opérateur pour obtenir le résultat d'un DUP
    opdup* dup= new opdup();
    //! \brief Opérateur pour obtenir le résultat d'un modulo
    mod* modulo= new mod();


    // Opérateurs à créer
   /* //! \brief Opérateur pour obtenir le dénominateur d'un complexe
    den* duplication= new den();
    //! \brief Opérateur pour obtenir le dénominateur d'un complexe
    den* depilement= new den();
    //! \brief Opérateur pour obtenir le dénominateur d'un complexe
    den* interversion= new den();
    //! \brief Opérateur pour obtenir le dénominateur d'un complexe
    den* lastop= new den();
    //! \brief Opérateur pour obtenir le dénominateur d'un complexe
    den* lastarg= new den();*/

    ops[0] = addition;
    ops[1] = soustraction;
    ops[2] = multiplication;
    ops[3] = division;
    ops[4] = complexe;
    ops[5] = negatif;
    ops[6] = egalite;
    ops[7] = difference;
    ops[8] = superiorite;
    ops[9] = inferiorite;
    ops[10] = superouegal;
    ops[11] = inferouegal;

    ops[12] = diventiere;
    ops[13] = denominateur;
    ops[14] = numerateur;
    ops[15] = partieReelle;
    ops[16] = partieImaginaire;
    ops[17] = et;
    ops[18] = ou;
    ops[19] = non;
    ops[20] = ift;
    ops[21] = dup;
    ops[22] = eval;
    ops[23] = modulo;
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
