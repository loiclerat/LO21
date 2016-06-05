/**
\file item.h
\date 03/06/2016
\author LoÃ¯c Lerat, AndrÃ©a Vibert, ThÃ©o Hordequin
\version 1.0
\brief  Elements de la Pile

Description de la classe Item

**/

#ifndef ITEM_H
#define ITEM_H

#include "litteralemanager.h"

/**
  \class Item
  \brief La classe Item est chargée de "stocker" un littérale pour être ensuité empilé sur la Pile
 */

class Item {
    //! \brief Littérale associée �  l'Item
    litterale* lit;

public:

    //! \brief Constructeur
    Item():lit(0){}
    //! \brief Associer une littérale �  l'Item
    void setLitterale(litterale& l) { lit=&l; }
    //! \brief Dissocier l'Item de la littérale associée
    void raz() { lit=0; }
    //! \brief Retourne une référence vers la littérale associée �  l'Item
    litterale& getLitterale() const;
};

#endif // ITEM_H
