#ifndef LITTREELLE_H
#define LITTREELLE_H

#include"littnumerique.h"
#include <math.h>


/*avec de la manipulation de char on va réussir à obtenir le nombre (i)
*de chiffres après la virgule et on pourra transformer en int puis faire i itération du int*0.1 et stocker dans la partie entière
*/

class littReelle : public littNumerique{
    float valeur;
    int entiere;
    float decimale;
public :
    littReelle(int e, float d): valeur(e+d), entiere(e), decimale(d){}
    littReelle(float d): valeur (d), entiere(0), decimale(d){}//ne prend que les .45 et le traduit directement comme un 0.45

    //pas de constructeur avec seulement e sinon on a un entier

    //pas besoin de def de construct par recop, car celui par def suffit
    littReelle(const littReelle&){}
    ~littReelle(){}
    float getValeur() const{return valeur;}
    int getEntiere() const{return entiere;}
    float getDecimale() const{return decimale;}
    //void simplifier();

    ostream& affichage(ostream& f=cout)const{f<<getValeur(); return f;}
    void NEG(){valeur=valeur*(-1); entiere=entiere*(-1);}

    littReelle& operator+(littReelle& b);
    littReelle& operator-(littReelle& b);
    //littRelle& operator*(littEntiere& b);
    //DIV
};

#endif // LITTREELLE_H
