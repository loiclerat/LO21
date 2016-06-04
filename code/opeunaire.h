#ifndef OPEUNAIRE_H
#define OPEUNAIRE_H

#include"litterale.h"

class unaire{
public :
    virtual litterale& traitement(litterale& a)=0;
};

#endif // OPEUNAIRE_H
