#ifndef PILE_H
#define PILE_H

#include <QObject>
#include <QTextStream>

#include "item.h"
#include "litterale.h"

class Pile : public QObject {
    Q_OBJECT

    Item* items;
    unsigned int nb;
    unsigned int nbMax;
    QString message;
    unsigned int nbAffiche;

    void agrandissementCapacite();

public:

    Pile():items(0),nb(0),nbMax(0),message(""),nbAffiche(4){}
    ~Pile();

    void push(litterale& l);
    void pop();
    bool estVide() const { return nb==0; }
    unsigned int taille() const { return nb; }
    void affiche(QTextStream& f) const;
    litterale& top() const;
    void setNbItemsToAffiche(unsigned int n) { nb=n; }
    unsigned int getNbItemsToAffiche() const { return nbAffiche; }
    void setMessage(const QString& m) { message=m; modificationEtat(); }
    QString getMessage() const { return message; }


    // === ITERATEURS ===
    class iterator {
        Item* current;
        iterator(Item* u):current(u){}
        friend class Pile;
    public:
        iterator():current(0){}
        litterale& operator*() const { return current->getLitterale(); }
        bool operator!=(iterator it) const { return current!=it.current; }
        iterator& operator++(){ --current; return *this; }
    };
    iterator begin() { return iterator(items+nb-1); }
    iterator end() { return iterator(items-1); }

    class const_iterator {
        Item* current;
        const_iterator(Item* u):current(u){}
        friend class Pile;
    public:
        const_iterator():current(0){}
        const litterale& operator*() const { return current->getLitterale(); }
        bool operator!=(const_iterator it) const { return current!=it.current; }
        const_iterator& operator++(){ --current; return *this; }
    };
    const_iterator begin() const { return const_iterator(items+nb-1); }
    const_iterator end() const { return const_iterator(items-1); }

    // === SIGNAUX ===

signals:
    void modificationEtat();

};

#endif // PILE_H
