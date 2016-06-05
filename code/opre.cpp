#include "opre.h"
#include "divs.h"

litterale& opre::traitement(litteraleManager& mng, litterale& a)
{

    littNumerique* num = dynamic_cast<littNumerique*>(&a);
    littcomplexe* comp = dynamic_cast<littcomplexe*>(&a);

    if (comp != 0) {
        return mng.addLitterale(comp->getPartRe());
    }
    else if (num != 0) {
        return mng.addLitterale(num);
    }
    else {
        throw ComputerException("Ce n'est pas un nombre!");
    }
}
