/**
\file item.h
\date 03/06/2016
\author LoÃƒÂ¯c Lerat, AndrÃƒÂ©a Vibert, ThÃƒÂ©o Hordequin
\version 1.0
\brief  Elements de la Pile

Description de la classe Item

**/

#ifndef ITEM_H
#define ITEM_H
#include "litterale.h"

/**
  \class Item
  \brief La classe Item est chargÃ©e de "stocker" un littÃ©rale pour Ãªtre ensuitÃ© empilÃ© sur la Pile
 */

class Item {
    //! \brief LittÃ©rale associÃ©e Ã  l'Item
    litterale* lit;

public:

    //! \brief Constructeur
    Item():lit(0){}
    //! \brief Destructeur
    ~Item(){}
    //! \brief Associer une littÃ©rale Ã  l'Item
    void setLitterale(litterale& l) { lit=&l; }
    //! \brief Dissocier l'Item de la littÃ©rale associÃ©e
    void raz() { lit=0; }
    //! \brief Retourne une rÃ©fÃ©rence vers la littÃ©rale associÃ©e Ã  l'Item
    litterale& getLitterale() const;
};

#endif // ITEM_H
