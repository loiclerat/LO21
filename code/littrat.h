#ifndef LITTRAT_H
#define LITTRAT_H


#include "littnumerique.h"
#include "littentiere.h"

class littrat : public littNumerique
{
    int num;
    int den;
public:
    littrat(int n=0, int d=1){
        num = n;
        den = d;
        try{
        simplifier();
        }catch (ComputerException e){
            e.getInfo();
        }
    }
    ~littrat(){}
    void simplifier();
    int getNum()const { return num; }
    int getDen()const { return den; }
    QString affichage(QString f="")const{
        f.append(QString::number(getNum()));
        f.append("/");
        f.append(QString::number(getDen()));
        return f;
    }

    /*==========*/
    littrat* operator+(littrat* b);
    littNumerique* operator+(littNumerique* a);
    littnumber* operator+(littnumber* a);
    /*==========*/
    littrat& operator-(littrat& b);
    littrat* operator-(littrat* b);
    littNumerique* operator-(littNumerique* a);
    littnumber* operator-(littnumber* a);
    /*==========*/
    littrat& operator*(littrat& b);
    littrat* operator*(littrat* b);
    littNumerique* operator*(littNumerique* a);
    littnumber* operator*(littnumber* a);
    /*==========*/
    littrat& operator/(littrat& b);
    littrat* operator/(littrat* b);
    littNumerique* operator/(littNumerique* a);
    littnumber* operator/(littnumber* a);
    /*==========*/

    void NEG(){
        num=-num;
    }

};


#endif // LITTRAT_H
