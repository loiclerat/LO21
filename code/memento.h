/**
\file memento.h
\date 03/06/2016
\author Loïc Lerat, Andr�a Vibert, Th�o Hordequin
\version 1.0

Description de la classe Memento et CareTaker impl�mentant le design pattern Memento

**/

#ifndef MEMENTO_H
#define MEMENTO_H

#include "pile.h"
#include <vector>

//! \class Memento
//! \brief Permet la sauvegarde et la r�cup�ration d'un �tat de la pile
class Memento{
    //! \brief Pointeur sur Pile
    Pile* etat;

public:
    //! \brief Constructeur
    //! \n Sauvegarde de la pile pass�e en param�tre dans un Memento
    Memento(Pile& p){ etat = new Pile(p); }

    //! \brief R�cup�rer la pile sauvegard�e dans le Memento
    Pile& getEtat() const {return *etat;}

    //! \brief Destructeur : on d�truit la pile sauvegard�e
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

    //! \brief R�cup�rer la i�me sauvegarde dans l'historique
    Memento& get(unsigned int i) const {return *historique[i];}

    //! \brief Taille de l'historique
    unsigned int taille() const { return historique.size(); }

    //! \brief Suppression de la derni�re sauvegarde dans l'historique
    void pop(){ historique.pop_back();}

};


#endif // MEMENTO_H
