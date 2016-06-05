#ifndef OPERATEUR_LOGIQUE_H
#define OPERATEUR_LOGIQUE_H

#include "operateur.h"

class operateur_logique : public operateur {
public:
    operateur_logique(int a, QString s):operateur(a, s){}

    virtual litterale& traitement(litteraleManager& mng, litterale& a, litterale& b)=0;
    virtual litterale& traitement(litteraleManager& mng, litterale& a)=0;
};


#endif // OPERATEUR_LOGIQUE_H
