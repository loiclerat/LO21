#ifndef OPERATEURMANAGER_H
#define OPERATEURMANAGER_H

#include "operateur.h"

class operateurManager {
    operateur** ops;           //Liste des littérales
    unsigned int nb;
    unsigned int nbMax;

    void agrandissementCapacite();

    operateurManager():ops(0),nb(0),nbMax(0){}
    ~operateurManager();
    operateurManager(const operateurManager& m);
    operateurManager& operator=(const operateurManager& m);

    struct Handler{
        operateurManager* instance;
        Handler():instance(0){}
        // destructeur appelé �  la fin du programme
        ~Handler(){ delete instance; }
    };
    static Handler handler;

public:

    // Méthode addoperateur

    void removeoperateur(operateur& o);

    static operateurManager& getInstance();
    static void libererInstance();

    // === ITERATEURS ===

    class iterator {
        operateur** current;
        iterator(operateur** u):current(u){}
        friend class operateurManager;
    public:
        iterator():current(0){}
        operateur& operator*() const { return **current; }
        bool operator!=(iterator it) const { return current!=it.current; }
        iterator& operator++(){ ++current; return *this; }
    };
    iterator begin() { return iterator(ops); }
    iterator end() { return iterator(ops+nb); }

    class const_iterator {
        operateur** current;
        const_iterator(operateur** u):current(u){}
        friend class operateurManager;
    public:
        const_iterator():current(0){}
        operateur& operator*() const { return **current; }
        bool operator!=(const_iterator it) const { return current!=it.current; }
        const_iterator& operator++(){ ++current; return *this; }
    };
    const_iterator begin_const() const { return const_iterator(ops); }
    const_iterator end_const() const { return const_iterator(ops+nb); }

};

#endif // OPERATEURMANAGER_H
