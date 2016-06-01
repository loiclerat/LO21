#ifndef OPERATEUR_NUMERIQUE_H
#define OPERATEUR_NUMERIQUE_H
#include "operateur.h"

class operateur_numerique : public operateur {
public:
    operateur_numerique(int a):operateur(a){};
    virtual litterale& traitement(litterale& a, litterale& b)=0;
    //virtual litterale* traitement(litterale* a)=0;
};



#endif // OPERATEUR_NUMERIQUE_H
