/**
\file item.cpp
\date 03/06/2016
\author Loïc Lerat, Andréa Vibert, Théo Hordequin
\version 1.0
\brief  Définition des méthodes de la classe Item


**/

#include "item.h"

//! \brief Retourne une référence vers la littérale associée à l'Item
litterale& Item::getLitterale() const {
        if (lit==0) throw ComputerException("Item : tentative d'acces a une litterale inexistante");
        return *lit;
}
