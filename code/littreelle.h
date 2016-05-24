#ifndef LITTREELLE_H
#define LITTREELLE_H

#include"littnumerique.h"

class littReelle : public littNumerique{
    float valeur;
    int entiere;
    int decimale;
public :
    littReelle(int e):entiere(e),decimale(0){}
    littReelle(int e, int d):entiere(e),decimale(d){}
    //pas besoin de def de construct par recop, car celui par def suffit
    littReelle(const littReelle&){}
    ~littReelle(){}
    float getValeur() const{return entiere+0.1*decimale;}
    int getEntiere() const{return entiere;}
    int getDecimale() const{return decimale;}
    //void simplifier();

    ostream& affichage(ostream& f=cout)const{f<<getValeur(); return f;}
    void NEG(){valeur=valeur*(-1); entiere=entiere*(-1);}

    //littReelle& operator+(littReelle& b);
    //littReelle& operator-(littReelle& b);
    //littRelle& operator*(littEntiere& b);
    //DIV
};

#endif // LITTREELLE_H
