#include "opre.h"
#include "divs.h"

litterale& opre::traitement(litterale& a)
{

    littNumerique* num = dynamic_cast<littNumerique*>(&a);
    littcomplexe* comp = dynamic_cast<littcomplexe*>(&a);

    if (comp != 0) {
        return *(comp->getPartRe());
    }
    else if (num != 0) {
        return *num;
    }
    else {
        throw ComputerException("Ce n'est pas un nombre!");
    }
}
