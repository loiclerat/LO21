/**
\file pile.h
\date 03/06/2016
\author Loïc Lerat, Andréa Vibert, Théo Hordequin
\version 1.0
\brief  Pile d'objets Item

Description de la classe Pile ainsi que ses itérateurs et signaux

**/

#ifndef PILE_H
#define PILE_H

#include <QObject>
#include <QTextStream>

#include "item.h"
#include "litterale.h"


/**
  \class Pile
  \brief La classe Pile est chargée de l'affichage des littérales ainsi que des messages destinés à l'utilisateur
 */

class Pile : public QObject {
    Q_OBJECT

    //! \brief Liste des Items constituants la pile
    Item* items;    
    //! \brief Nombre d'Items dans la pile
    unsigned int nb;    
    //! \brief Capacité de la Pile
    unsigned int nbMax;    
    //! \brief Message destiné à l'utilisateur
    QString message;
    //! \brief Nombre d'Items à afficher
    unsigned int nbAffiche;

    //! \brief Agrandissement de la Pile lorsque l'on dépasse la capacité actuelle
    void agrandissementCapacite();

public:

    //! \brief Constructeur
    Pile():items(0),nb(0),nbMax(0),message(""),nbAffiche(4){}
    //! \brief Destructeur
    ~Pile();

    //! \brief Ajouter une littérale au sommet de la pile
    void push(litterale& l);
    //! \brief Dépiler la littérale au sommet de la pile
    void pop();
    //! \brief Retourne false si la pile est vide
    bool estVide() const { return nb==0; }
    //! \brief Nombre d'Items dans la pile
    unsigned int taille() const { return nb; }
    //! \brief Retourne une référence vers la littérale au sommet de la Pile
    litterale& top() const;
    //! \brief Définir le nombre d'éléments de la Pile à afficher
    void setNbItemsToAffiche(unsigned int n) { nb=n; }
    //! \brief Nombre d'Items à afficher
    unsigned int getNbItemsToAffiche() const { return nbAffiche; }
    //! \brief Définir le message à afficher à l'utilisateur
    void setMessage(const QString& m) { message=m; modificationEtat(); }
    //! \brief Message à afficher
    QString getMessage() const { return message; }


    // === ITERATEURS ===

    /**
      \class iterator
      \brief iterateur sur les objets Item de la Pile
      \n iterator permet un parcours séquentiel des éléments de la pile en lecture et écriture
     */

    class iterator {
        //! \brief Item courant, sur lequel est positionné l'itérateur
        Item* current;

    public:

        //! \brief Constructeur
        iterator(Item* u=0):current(u){}
        //! \brief Surcharge de l'opérateur * pour récupérer la littérale pointée par l'Item courant
        litterale& operator*() const { return current->getLitterale(); }
        //! \brief Surcharge de l'opréateur != pour comparer deux itérateurs
        bool operator!=(iterator it) const { return current!=it.current; }
        //! \brief Surcharge de l'opérateur ++ pour avancer vers l'Item suivant
        iterator& operator++(){ --current; return *this; }
    };
    //! \brief Retourne un itérateur positionné sur le premier Item de la Pile
    iterator begin() { return iterator(items+nb-1); }
    //! \brief Retourne un itérateur positionné après le dernier Item de la Pile
    iterator end() { return iterator(items-1); }


    /**
      \class const_iterator
      \brief iterateur const sur les objets Item de la Pile
      \n const_iterator permet un parcours séquentiel des éléments de la pile en lecture seule
     */

    class const_iterator {
        //! \brief Item courant, sur lequel est positionné l'itérateur
        Item* current;

    public:

        //! \brief Constructeur
        const_iterator(Item* u=0):current(u){}
        //! \brief Surcharge de l'opérateur * pour récupérer la littérale pointée par l'Item courant
        const litterale& operator*() const { return current->getLitterale(); }
        //! \brief Surcharge de l'opréateur != pour comparer deux itérateurs
        bool operator!=(const_iterator it) const { return current!=it.current; }
        //! \brief Surcharge de l'opérateur ++ pour avancer vers l'Item suivant
        const_iterator& operator++(){ --current; return *this; }
    };
    //! \brief Retourne un itérateur const positionné sur le premier Item de la Pile
    const_iterator begin() const { return const_iterator(items+nb-1); }
    //! \brief Retourne un itérateur const positionné après le dernier Item de la Pile
    const_iterator end() const { return const_iterator(items-1); }

    // === SIGNAUX ===

signals:
    void modificationEtat();

};

#endif // PILE_H
