#ifndef LITTNUMBER_H
#define LITTNUMBER_H
#include "litterale.h"

using namespace std;

class littnumber : public litterale
{
public:
    littnumber(){}
    virtual ~littnumber(){}

    virtual QString& affichage(QString f="")const=0;//a definir
    virtual void simplifier(){}
    virtual void NEG()=0;

    virtual littnumber* operator+(littnumber* a)=0;
    virtual littnumber* operator-(littnumber* a)=0;
    virtual littnumber* operator*(littnumber* a)=0;
    virtual littnumber* operator/(littnumber* a)=0;


};

#endif // LITTNUMBER_H
