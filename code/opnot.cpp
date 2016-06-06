#include "opnot.h"

litterale& opnot::traitement(litteraleManager& mng, litterale& a)
{

    littnumber* num1 = dynamic_cast<littnumber*>(&a);

    if (num1 != 0) {
        if (num1->isNull()==true) {
            littEntiere ret(1);
            return mng.addLitterale(&ret);
        }
        else {
            littEntiere ret(0);
            return mng.addLitterale(&ret);
        }
    }
    else {
        throw ComputerException("Format incompatible des argument, nécessite un nombre");
    }

}
