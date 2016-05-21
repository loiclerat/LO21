#ifndef LITTNUMERIQUE_H
#define LITTNUMERIQUE_H
#include "litterale.h"

class littNumerique : public litterale{

public :
    littNumerique(){}
    virtual ~littNumerique(){}
    virtual ostream& affichage(ostream& f=cout)const=0;//a definir
    virtual void simplifier(){}

    //surchage des opérateurs qui peuvent être utilisés avec toutes les litérales numériques
    //virtual littNumerique& operator+(littNumerique& b)=0;
    virtual void NEG()=0;
};

#endif // LITTNUMERIQUE_H
