#ifndef OPERATEUR_H
#define OPERATEUR_H
#include "litterale.h"
#include "litteralemanager.h"

class operateur {
protected:
    int arite;
    QString symbol;
public:
    operateur(int a, QString s):arite(a), symbol(s){};
    int getArite(){return arite;}

    virtual litterale& traitement(litteraleManager& mng, litterale& a, litterale& b)=0;
    virtual litterale& traitement(litteraleManager& mng, litterale& a)=0;
};

#endif // OPERATEUR_H
