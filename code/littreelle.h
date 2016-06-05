#ifndef LITTREELLE_H
#define LITTREELLE_H

#include "littnumerique.h"
#include "littentiere.h"
#include <math.h>

/*avec de la manipulation de char on va rיussir א obtenir le nombre (i)
*de chiffres aprטs la virgule et on pourra transformer en int puis faire i itיration du int*0.1 et stocker dans la partie entiטre
*/

/*Dans les littReelles on n'aura de signe nיgatif que dans les parties entiטres
*
*/

class littReelle : public littNumerique {
    float valeur;
    int entiere;
    float decimale;

public:
    littReelle(int e, float d)
        : valeur(e + d)
        , entiere(e)
        , decimale(d)
    {
        simplifier();
    }
    littReelle(float d)
        : valeur(d)
        , entiere(0)
        , decimale(d)
    {
        simplifier();
    } //Ex : ne prend que les .45 et le traduit directement comme un 0.45

    //pas de constructeur avec seulement e sinon on a un entier

    //pas besoin de def de construct par recop, car celui par def suffit
    littReelle(const littReelle&) {}
    ~littReelle() {}
    float getValeur() const { return valeur; }
    int getEntiere() const { return entiere; }
    float getDecimale() const { return decimale; }
    void simplifier();

    bool isNull(){
        if(valeur==0.0){
            return true;
        }
        else return false;
    }

    bool isPos(){
        if(valeur>0){
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
    littReelle* operator+(littReelle* b);
    littReelle& operator+(littReelle& b);
    littNumerique* operator+(littNumerique* b);
    littnumber* operator+(littnumber* b);
    /*==========*/
    littReelle& operator-(littReelle& b);
    littReelle* operator-(littReelle* b);
    littNumerique* operator-(littNumerique* b);
    littnumber* operator-(littnumber* b);
    /*==========*/
    littReelle& operator*(littReelle& b);
    littReelle* operator*(littReelle* b);
    littNumerique* operator*(littNumerique* b);
    littnumber* operator*(littnumber* b);
    /*==========*/
    littReelle& operator/(littReelle& b);
    littReelle* operator/(littReelle* b);
    littNumerique* operator/(littNumerique* b);
    littnumber* operator/(littnumber* b);
    /*==========*/
};

#endif // LITTREELLE_H
