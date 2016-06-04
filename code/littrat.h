#ifndef LITTRAT_H
#define LITTRAT_H

#include"littnumerique.h"
#include "littentiere.h"

class littrat : public littNumerique
{
    int num;
    int den;
public:
    littrat(int n=0, int d=1){
        num = n;
        den = d;
        simplifier();
    }
    ~littrat(){}
    void simplifier();
    int getNum()const { return num; }
    int getDen()const { return den; }
    QString& affichage(QString f="")const{
        f.append(getNum());
        f.append("/");
        f.append(getDen());
        return f;
    }


    littrat* operator+(littrat* b);
    littNumerique* operator+(littNumerique* a);
    littrat& operator-(littrat& b);
    littrat& operator*(littrat& b);
    littrat& operator/(littrat& b);

    void NEG(){
        num=-num;
    }

};


#endif // LITTRAT_H
