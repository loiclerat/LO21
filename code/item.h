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
#include "exceptions.h"

/**
  \class Item
  \brief La classe Item est charg�e de "stocker" un litt�rale pour �tre ensuit� empil� sur la Pile
 */

class Item {
    //! \brief Litt�rale associ�e � l'Item
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
    //! \brief Associer une litt�rale � l'Item
    void setLitterale(litterale& l) { lit=&l; }
    //! \brief Dissocier l'Item de la litt�rale associ�e
    void raz() { lit=0; }
    //! \brief Retourne une r�f�rence vers la litt�rale associ�e � l'Item
    litterale& getLitterale() const;
};

#endif // ITEM_H
