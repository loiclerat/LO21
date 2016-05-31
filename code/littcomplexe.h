#ifndef LITTCOMPLEXE_H
#define LITTCOMPLEXE_H

#include "littnumerique.h"
using namespace std;

class littcomplexe : public littNumerique
{
    littNumerique* partRe;
    littNumerique* partIm;
public:
    littcomplexe(littNumerique* a, littNumerique* b){
        partRe = a;
        partIm = b;
    };

    littNumerique* getPartRe()const { return partRe; }
    littNumerique* getPartIm()const { return partIm; }

    virtual QString getText(){
        return "Test";
    };
    ostream& affichage(ostream& f=cout)const{
        partRe->affichage();
        f<<" $ ";
        partIm->affichage();
        f<<" \n ";
        return f;
    }

    ~littcomplexe(){ delete partRe; delete partIm;}
    void NEG(){
        partRe->NEG();
    }



};

#endif // LITTCOMPLEXE_H
