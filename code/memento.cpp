/**
\file memento.cpp
\date 03/06/2016
\author Loïc Lerat, Andr�a Vibert, Th�o Hordequin
\version 1.0

D�finition des m�thodes des classes Memento et CareTaker

**/

#include "memento.h"

//! \brief Ajout d'une sauvegarde dans l'historique
void CareTaker::add(Memento& etat, unsigned int i){
    // Cas o� l'on a chang� l'�tat de la pile apr�s un "Undo" (donc � partir d'un ancien �tat)
    if (i<historique.size()){
        historique[i]=&etat;
    }
    // Cas o� l'on est sur l'�tat le plus r�cent
    else historique.push_back(&etat);
}
