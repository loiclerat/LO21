/**
\file item.cpp
\date 03/06/2016
\author LoÃ¯c Lerat, Andr�a Vibert, Th�o Hordequin
\version 1.0
\brief  D�finition des m�thodes de la classe Item


**/

#include "item.h"

//! \brief Retourne une r�f�rence vers la litt�rale associ�e � l'Item
litterale& Item::getLitterale() const {
        if (lit==0) throw ComputerException("Item : tentative d'acces a une litterale inexistante");
        return *lit;
}
