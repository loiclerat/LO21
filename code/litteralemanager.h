/**
\file litteralemanager.h
\date 03/06/2016
\author Loïc Lerat, Andréa Vibert, Théo Hordequin
\version 1.0
\brief  Littérale Manager

Description de la classe litteraleManager et de ses itérateurs

**/


#ifndef litteraleMANAGER_H
#define litteraleMANAGER_H

#include "litterale.h"
#include "littentiere.h"
#include "littreelle.h"
#include "littrat.h"

class litteraleManager {
    litterale** litts;           //Liste des littérales
    unsigned int nb;
    unsigned int nbMax;

    void agrandissementCapacite();

    litteraleManager():litts(0),nb(0),nbMax(0){}
    ~litteraleManager();
    litteraleManager(const litteraleManager& m);
    litteraleManager& operator=(const litteraleManager& m);

    struct Handler{
        litteraleManager* instance;
        Handler():instance(0){}
        // destructeur appelé à la fin du programme
        ~Handler(){ delete instance; }
    };
    static Handler handler;

public:

    // Méthode addlitterale : surcharges pour chaque type de littérale
    // avec les bons paramètres pour les créer
    litterale& addLitterale(littEntiere l);     //littentiere

    void removelitterale(litterale& l);

    static litteraleManager& getInstance();
    static void libererInstance();

    // === ITERATEURS ===

    // Vérifier l'utilité du constructeur privé et du friend

    class iterator {
        litterale** current;
        iterator(litterale** u):current(u){}
        friend class litteraleManager;
    public:
        iterator():current(0){}
        litterale& operator*() const { return **current; }
        bool operator!=(iterator it) const { return current!=it.current; }
        iterator& operator++(){ ++current; return *this; }
    };
    iterator begin() { return iterator(litts); }
    iterator end() { return iterator(litts+nb); }

    class const_iterator {
        litterale** current;
        const_iterator(litterale** u):current(u){}
        friend class litteraleManager;
    public:
        const_iterator():current(0){}
        litterale& operator*() const { return **current; }
        bool operator!=(const_iterator it) const { return current!=it.current; }
        const_iterator& operator++(){ ++current; return *this; }
    };
    const_iterator begin() const { return const_iterator(litts); }
    const_iterator end() const { return const_iterator(litts+nb); }

};

#endif // litteraleMANAGER_H
