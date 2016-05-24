#ifndef LITTENTIERE_H
#define LITTENTIERE_H
#include"littnumerique.h"

class littEntiere: public littNumerique{
    int valeur;
public :
    littEntiere(int val): valeur(val){}
    //pas besoin de construct par recop, car celui par def suffit
    littEntiere(const littEntiere&){}
    ~littEntiere(){}
    int getValeur() const{return valeur;}
    void simplifier(){};

    ostream& affichage(ostream& f=cout)const{f<<getValeur(); return f;}
    void NEG(){valeur=(-valeur);}

    littEntiere& operator+(littEntiere& b);
    littEntiere& operator-(littEntiere& b);
    littEntiere& operator*(littEntiere& b);
    //DIV
};
#endif LITTENTIERE_H
