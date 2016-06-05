#include "opim.h"

litterale& opim::traitement(litteraleManager& mng, litterale& a)
{

    littNumerique* num = dynamic_cast<littNumerique*>(&a);
    littcomplexe* comp = dynamic_cast<littcomplexe*>(&a);

    if (comp != 0) {
        return mng.addLitterale(comp->getPartIm());
    }
    else if (num != 0) {
        littEntiere x(0);
        return mng.addLitterale(&x);
    }
    else {
        throw ComputerException("Ce n'est pas un nombre!");
    }
}
