#ifndef LITTENTIERE_H
#define LITTENTIERE_H

#include "littrat.h"
#include "littnumerique.h"
#include "littreelle.h"
#include "littcomplexe.h"

class littEntiere : public littNumerique {
    int valeur;

public:
    littEntiere(int val)
        : valeur(val)
    {
    }
    //pas besoin de construct par recop, car celui par def suffit
    littEntiere(const littEntiere&) {}
    ~littEntiere() {}
    int getValeur() const { return valeur; }
    void simplifier() {}

    bool isNull(){
        if(valeur==0){
            return true;
        }
        else return false;
    }

    QString affichage(QString f = "") const
    {
        f.append(QString::number(getValeur()));
        return f;
    }

    /*==========*/
    littEntiere& operator+(littEntiere& b);
    littNumerique* operator+(littNumerique* a);
    littnumber* operator+(littnumber* a);
    /*==========*/
    littEntiere& operator-(littEntiere& b);
    littNumerique* operator-(littNumerique* a);
    littnumber* operator-(littnumber* a);
    /*==========*/
    littEntiere& operator*(littEntiere& b);
    littNumerique* operator*(littNumerique* a);
    littnumber* operator*(littnumber* a);
    /*==========*/
    littNumerique* operator/(littEntiere* b);
    littNumerique* operator/(littNumerique* a);
    littnumber* operator/(littnumber* a);
    /*==========*/
};

#endif //LITTENTIERE_H
