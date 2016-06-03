#ifndef LITTNUMERIQUE_H
#define LITTNUMERIQUE_H
#include "litterale.h"

using namespace std;

class littNumerique : public litterale{

public :
    littNumerique(){}
    virtual ~littNumerique(){}
    virtual ostream& affichage(ostream& f=cout)const=0;//a definir
    virtual void simplifier(){}

    //surchage des op�rateurs qui peuvent �tre utilis�s avec toutes les lit�rales num�riques
    //virtual littNumerique& operator+(littNumerique& b)=0;
    virtual void NEG()=0;
    virtual littNumerique* operator+(littNumerique* a)=0;
};

#endif // LITTNUMERIQUE_H
