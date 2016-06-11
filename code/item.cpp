/**
\file item.cpp
\date 03/06/2016
\author LoÃ¯c Lerat, AndrÃ©a Vibert, ThÃ©o Hordequin
\version 1.0
\brief  Définition des méthodes de la classe Item


**/

#include "item.h"

//! \brief Retourne une référence vers la littérale associée �  l'Item
litterale& Item::getLitterale() const {
        if (lit==0) throw ComputerException("Item : tentative d'acces a une litterale inexistante");
        return *lit;
}
