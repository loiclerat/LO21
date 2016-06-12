/**
\file item.h
\date 03/06/2016
\author LoÃƒÆ’Ã‚Â¯c Lerat, AndrÃƒÆ’Ã‚Â©a Vibert, ThÃƒÆ’Ã‚Â©o Hordequin
\version 1.0
\brief  Elements de la Pile

Description de la classe Item

**/

#ifndef ITEM_H
#define ITEM_H
#include "litterale.h"
#include "exceptions.h"

/**
  \class Item
  \brief La classe Item est chargée de "stocker" un littérale pour être ensuité empilé sur la Pile
 */

class Item {
    //! \brief Littérale associée à l'Item
    litterale* lit;

public:

    //! \brief Constructeur
    Item():lit(0){}
    Item& operator=(Item& i){
        if (this != &i)
            lit = &i.getLitterale();
    }
    //! \brief Destructeur
    ~Item(){}
    //! \brief Associer une littérale à l'Item
    void setLitterale(litterale& l) { lit=&l; }
    //! \brief Dissocier l'Item de la littérale associée
    void raz() { lit=0; }
    //! \brief Retourne une référence vers la littérale associée à l'Item
    litterale& getLitterale() const;
};

#endif // ITEM_H
