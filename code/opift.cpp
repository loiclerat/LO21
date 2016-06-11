#include "opift.h"

litterale& opIft::traitement(litterale& a, litterale& b)
{

    littEntiere* booleen = dynamic_cast<littEntiere*>(&a);
    littProgramme* prog = dynamic_cast<littProgramme*>(&b);

    if (booleen != 0 && prog != 0) {
        if(booleen->getValeur()==1){
            opeval* ope = new opeval();
            ope->traitement(*prog);
        }
        else
            throw ComputerException("La valeur est 0, on abandonne");
    }
    else {
        throw ComputerException("Format incompatible des argument, nécessite un nombre et un programme");
    }
}
