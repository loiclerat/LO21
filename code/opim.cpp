#include "opim.h"

litterale& opim::traitement(litterale& a)
{

    littNumerique* num = dynamic_cast<littNumerique*>(&a);
    littcomplexe* comp = dynamic_cast<littcomplexe*>(&a);

    if (comp != 0) {
        return *(comp->getPartIm());
    }
    else if (num != 0) {
        littEntiere* x = new littEntiere(0);
        return *x;
    }
    else {
        throw ComputerException("Ce n'est pas un nombre!");
    }
}
