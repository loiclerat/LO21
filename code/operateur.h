#ifndef OPERATEUR_H
#define OPERATEUR_H
#include "litterale.h"

class operateur : public Operande {
protected:
    int arite;
    QString symbol;
public:
    operateur(int a, QString s):arite(a), symbol(s){}
    int getArite(){return arite;}
    QString getSymbol(){return symbol;}

    virtual litterale& traitement(litterale& a, litterale& b)=0;
    virtual litterale& traitement(litterale& a)=0;
};

#endif // OPERATEUR_H
