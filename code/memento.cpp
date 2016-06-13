/**
\file memento.cpp
\date 03/06/2016
\author Loïc Lerat, Andréa Vibert, Théo Hordequin
\version 1.0

Définition des méthodes des classes Memento et CareTaker

**/

#include "memento.h"

//! \brief Ajout d'une sauvegarde dans l'historique
void CareTaker::add(Memento& etat, unsigned int i){
    // Cas où l'on a changé l'état de la pile après un "Undo" (donc à partir d'un ancien état)
    if (i<historique.size()){
        historique[i]=&etat;
    }
    // Cas où l'on est sur l'état le plus récent
    else historique.push_back(&etat);
}
