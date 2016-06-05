#ifndef LITTNUMERIQUE_H
#define LITTNUMERIQUE_H
#include "littnumber.h"


using namespace std;

class littNumerique : public littnumber{

public :
    littNumerique(){}
    virtual ~littNumerique(){}

    virtual QString affichage(QString f="")const=0;//a definir
    virtual void simplifier(){}
    virtual bool isNull()=0;
    virtual bool isPos()=0;



    /*==========*/
    virtual littNumerique* operator+(littNumerique* a)=0;
    virtual littNumerique* operator-(littNumerique* a)=0;
    virtual littNumerique* operator*(littNumerique* a)=0;
    virtual littNumerique* operator/(littNumerique* a)=0;
    /*==========*/
    virtual littnumber* operator+(littnumber* a)=0;
    virtual littnumber* operator-(littnumber* a)=0;
    virtual littnumber* operator*(littnumber* a)=0;
    virtual littnumber* operator/(littnumber* a)=0;
    /*==========*/
};
#endif // LITTNUMERIQUE_H
