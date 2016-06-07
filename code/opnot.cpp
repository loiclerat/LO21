#include "opnot.h"

litterale& opnot::traitement(litterale& a)
{

    littnumber* num1 = dynamic_cast<littnumber*>(&a);

    if (num1 != 0) {
        if (num1->isNull()==true) {
            littEntiere* ret = new littEntiere(1);
            return *ret;
        }
        else {
            littEntiere* ret = new littEntiere(0);
            return *ret;
        }
    }
    else {
        throw ComputerException("Format incompatible des argument, nécessite un nombre");
    }

}
