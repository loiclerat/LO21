/**
\file memento.h
\date 03/06/2016
\author Loïc Lerat, Andréa Vibert, Théo Hordequin
\version 1.0

Description de la classe Memento et CareTaker implémentant le design pattern Memento

**/

#ifndef MEMENTO_H
#define MEMENTO_H

#include "pile.h"
#include <vector>

//! \class Memento
//! \brief Permet la sauvegarde et la récupération d'un état de la pile
class Memento{
    //! \brief Pointeur sur Pile
    Pile* etat;

public:
    //! \brief Constructeur
    //! \n Sauvegarde de la pile passée en paramètre dans un Memento
    Memento(Pile& p){ etat = new Pile(p); }

    //! \brief Récupérer la pile sauvegardée dans le Memento
    Pile& getEtat() const {return *etat;}

    //! \brief Destructeur : on détruit la pile sauvegardée
    ~Memento(){delete etat;}

};

//!\class CareTaker
//! \brief Permet le stockage des sauvegardes successives de la pile
class CareTaker {
    //! \brief Vecteur de Memento, il contient l'historique des sauvegardes
    vector<Memento*> historique;

public:

    //! \brief Ajout d'une sauvegarde dans l'historique
    void add(Memento& etat, unsigned int i);

    //! \brief Récupérer la ième sauvegarde dans l'historique
    Memento& get(unsigned int i) const {return *historique[i];}

    //! \brief Taille de l'historique
    unsigned int taille() const { return historique.size(); }

    //! \brief Suppression de la dernière sauvegarde dans l'historique
    void pop(){ historique.pop_back();}

};


#endif // MEMENTO_H
