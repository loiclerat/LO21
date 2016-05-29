#ifndef ITEM_H
#define ITEM_H

#include "litterale.h"

class Item {
    litterale* lit;
public:
    Item():lit(0){}
    void setLitterale(litterale& l) { lit=&l; }
    void raz() { lit=0; }
    litterale& getLitterale() const;
};

#endif // ITEM_H
