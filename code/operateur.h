#ifndef OPERATEUR_H
#define OPERATEUR_H
#include "litterale.h"

class operateur {
protected:
    int arite;
public:
    operateur(int a):arite(a){};
    virtual litterale& traitement(litterale& a, litterale& b)=0;
    //virtual litterale* traitement(litterale* a)=0;
};

#endif // OPERATEUR_H
