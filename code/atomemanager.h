#ifndef ATOMEMANAGER_H
#define ATOMEMANAGER_H

#include "exceptions.h"
#include "littatome.h"
#include <QString>
#include <QMap>

/**
  \class atomeManager
  \brief La classe atomeManager est chargée de la gestion les atomes par une map
 */
/*
class atomeManager {
    //! \brief Liste des atomes
    atome** ops;
    //! \brief Nombre d'operateur dans la liste
    static unsigned int nb;
public:
    //! \brief Constructeur
    operateurManager();
    //! \brief Destructeur
    ~operateurManager();
    //! \brief Constructeur par recopie
    operateurManager(const operateurManager& m);
    //! \brief Opérateur d'affectation
    operateurManager& operator=(const operateurManager& m);

    //! \struct Handler
    //! \brief Handler responsable du cycle de vie de operateur Manager (Singleton)
    struct Handler{
        //! \brief Unique instance d'operateurManager
        operateurManager* instance;
        //! \brief Constructeur
        Handler():instance(0){}
        //! \brief Destructeur appelé �  la fin du programme
        ~Handler(){ delete instance; }
    };

    //! \brief Handler static pour faire d'operateurManager une classe singleton
    static Handler handler;

public:

    //! \brief Récupérer l'instance unique d'operateurManager
    static operateurManager& getInstance();
    //! \brief Libération de l'instance
    static void libererInstance();


    // === ITERATEURS ===

    // Vérifier l'utilité du constructeur privé et du friend
*/
    /**
      \class iterator
      \brief iterateur sur les objets operateur de operateurManager
      \n iterator permet un parcours séquentiel des éléments du manager en lecture et écriture
     */

/*
    class iterator {
        //! \brief élément courant, sur lequel est positionné l'itérateur
        operateur** current;

    public:

        //! \brief Constructeur
        iterator(operateur** u):current(u){}
        //! \brief Surcharge de l'opérateur " * " pour récupérer l'operateur pointé par l'élément courant
        operateur& operator*() const { return **current; }
        //! \brief Surcharge de l'opréateur " != " pour comparer deux itérateurs
        bool operator!=(iterator it) const { return current!=it.current; }
        //! \brief Surcharge de l'opérateur " ++ " pour avancer vers l'élément suivant
        iterator& operator++(){ ++current; return *this; }
    };
    //! \brief Retourne un itérateur positionné sur le premier operateur de la liste
    iterator begin() { return iterator(ops); }
    //! \brief Retourne un itérateur positionné après le dernier operateur de la liste
    iterator end() { return iterator(ops+nb); }

      \class const_iterator
      \brief iterateur const sur les objets operateur de operateurManager
      \n const_iterator permet un parcours séquentiel des éléments du manager en lecture seule
  class const_iterator {
        //! \brief Constructeur
        operateur** current;

    public:

        //! \brief Constructeur
        const_iterator(operateur** u):current(u){}
        //! \brief Surcharge de l'opérateur " * " pour récupérer l'operateur pointé par l'élément courant
        operateur& operator*() const { return **current; }
        //! \brief Surcharge de l'opréateur " != " pour comparer deux itérateurs
        bool operator!=(const_iterator it) const { return current!=it.current; }
        //! \brief Surcharge de l'opérateur " ++ " pour avancer vers l'élément suivant
        const_iterator& operator++(){ ++current; return *this; }
    };
    //! \brief Retourne un itérateur positionné sur le premier operateur de la liste
    const_iterator begin_const() const { return const_iterator(ops); }
    //! \brief Retourne un itérateur positionné après le dernier operateur de la liste
    const_iterator end_const() const { return const_iterator(ops+nb); }

};*/
#endif // ATOMEMANAGER_H
