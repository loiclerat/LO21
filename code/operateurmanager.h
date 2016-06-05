/**
\file operateurmanager.h
\date 03/06/2016
\author Lo�c Lerat, Andr�a Vibert, Th�o Hordequin
\version 1.0
\brief  Operateur Manager

Description de la classe operateurManager et de ses it�rateurs

**/


#ifndef OPERATEURMANAGER_H
#define OPERATEURMANAGER_H

#include "operateur.h"
#include "add.h"

/**
  \class operateurManager
  \brief La classe operateurManager est charg�e de la gestion les operateurs
 */

class operateurManager {
    //! \brief Liste des operateurs
    operateur** ops;
    //! \brief Nombre d'operateur dans la liste
    unsigned int nb;
public:
    //! \brief Op�rateur d'addition
    add addition;


    //! \brief Constructeur
    operateurManager();
    //! \brief Destructeur
    ~operateurManager();
    //! \brief Constructeur par recopie
    operateurManager(const operateurManager& m);
    //! \brief Op�rateur d'affectation
    operateurManager& operator=(const operateurManager& m);

    //! \struct Handler
    //! \brief Handler responsable du cycle de vie de operateur Manager (Singleton)
    struct Handler{
        //! \brief Unique instance d'operateurManager
        operateurManager* instance;
        //! \brief Constructeur
        Handler():instance(0){}
        //! \brief Destructeur appel� � la fin du programme
        ~Handler(){ delete instance; }
    };

    //! \brief Handler static pour faire d'operateurManager une classe singleton
    static Handler handler;

public:

    //! \brief R�cup�rer l'instance unique d'operateurManager
    static operateurManager& getInstance();
    //! \brief Lib�ration de l'instance
    static void libererInstance();


    // === ITERATEURS ===

    // V�rifier l'utilit� du constructeur priv� et du friend

    /**
      \class iterator
      \brief iterateur sur les objets operateur de operateurManager
      \n iterator permet un parcours s�quentiel des �l�ments du manager en lecture et �criture
     */
    class iterator {
        //! \brief �l�ment courant, sur lequel est positionn� l'it�rateur
        operateur** current;

    public:

        //! \brief Constructeur
        iterator(operateur** u):current(u){}
        //! \brief Surcharge de l'op�rateur " * " pour r�cup�rer l'operateur point� par l'�l�ment courant
        operateur& operator*() const { return **current; }
        //! \brief Surcharge de l'opr�ateur " != " pour comparer deux it�rateurs
        bool operator!=(iterator it) const { return current!=it.current; }
        //! \brief Surcharge de l'op�rateur " ++ " pour avancer vers l'�l�ment suivant
        iterator& operator++(){ ++current; return *this; }
    };
    //! \brief Retourne un it�rateur positionn� sur le premier operateur de la liste
    iterator begin() { return iterator(ops); }
    //! \brief Retourne un it�rateur positionn� apr�s le dernier operateur de la liste
    iterator end() { return iterator(ops+nb); }

    /**
      \class const_iterator
      \brief iterateur const sur les objets operateur de operateurManager
      \n const_iterator permet un parcours s�quentiel des �l�ments du manager en lecture seule
     */
    class const_iterator {
        //! \brief Constructeur
        operateur** current;

    public:

        //! \brief Constructeur
        const_iterator(operateur** u):current(u){}
        //! \brief Surcharge de l'op�rateur " * " pour r�cup�rer l'operateur point� par l'�l�ment courant
        operateur& operator*() const { return **current; }
        //! \brief Surcharge de l'opr�ateur " != " pour comparer deux it�rateurs
        bool operator!=(const_iterator it) const { return current!=it.current; }
        //! \brief Surcharge de l'op�rateur " ++ " pour avancer vers l'�l�ment suivant
        const_iterator& operator++(){ ++current; return *this; }
    };
    //! \brief Retourne un it�rateur positionn� sur le premier operateur de la liste
    const_iterator begin_const() const { return const_iterator(ops); }
    //! \brief Retourne un it�rateur positionn� apr�s le dernier operateur de la liste
    const_iterator end_const() const { return const_iterator(ops+nb); }

};

#endif // OPERATEURMANAGER_H
