#ifndef LITTCOMPLEXE_H
#define LITTCOMPLEXE_H

#include "littnumber.h"
#include "littnumerique.h"
#include "littentiere.h"
#include "littrat.h"
#include "littreelle.h"

using namespace std;

class littcomplexe : public littnumber {
    littNumerique* partRe;
    littNumerique* partIm;

public:
    littcomplexe(littNumerique* a, littNumerique* b)
    {
        partRe = a;
        partIm = b;
    }

    littcomplexe(littcomplexe const&);

    littNumerique* getPartRe() const { return partRe; }
    littNumerique* getPartIm() const { return partIm; }

    void simplifier() {}

    bool isNull(){
        if(partRe->isNull()==true){
            if(partIm->isNull()==true){
                return true;
            }else return false;
        }
        else return false;
    }

    bool isPos(){
        if(partRe->isPos()==true){
            if(partIm->isPos()==true){
                return true;
            }else return false;
        }
        else return false;
    }



    QString affichage(QString f = "") const
    {
        f.append(getPartRe()->affichage());
        f.append(" $ ");
        f.append(getPartIm()->affichage());
        return f;
    }

    ~littcomplexe()
    {
        delete partRe;
        delete partIm;
    }

    /*==========*/
    littnumber* operator+(littnumber* a);
    /*==========*/
    littnumber* operator-(littnumber* a);
    /*==========*/
    littnumber* operator*(littnumber* a);
    /*==========*/
    littnumber* operator/(littnumber* a);
};

#endif // LITTCOMPLEXE_H
