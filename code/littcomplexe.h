#ifndef LITTCOMPLEXE_H
#define LITTCOMPLEXE_H

#include "littnumber.h"
#include "littnumerique.h"
#include "littentiere.h"
#include "littrat.h"
#include "littreelle.h"

using namespace std;

class littcomplexe : public littnumber
{
    littNumerique* partRe;
    littNumerique* partIm;
public:
    littcomplexe(littNumerique* a, littNumerique* b){
        partRe = a;
        partIm = b;
    }


    littcomplexe(littcomplexe const&);


    littNumerique* getPartRe()const { return partRe; }
    littNumerique* getPartIm()const { return partIm; }

    void simplifier(){}

    QString& affichage(QString f="")const{
        f.append(partRe->affichage());
        f.append(" $ ");
        f.append(partIm->affichage());
        return f;
    }

    ~littcomplexe(){ delete partRe; delete partIm;}
    void NEG(){
        partRe->NEG();
    }


    /*==========*/
    //littcomplexe* operator+(littcomplexe* b);
    littnumber* operator+(littnumber* a);
    /*==========*/
    littnumber* operator-(littnumber* a);
    //littcomplexe* operator-(littcomplexe* b);
    /*==========*/
    littnumber* operator*(littnumber* a);
    //littcomplexe* operator*(littcomplexe* b);
    /*==========*/
    littnumber* operator/(littnumber* a);
    //littcomplexe* operator/(littcomplexe* b);


};

#endif // LITTCOMPLEXE_H
