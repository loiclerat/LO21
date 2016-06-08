#include "opand.h"

litterale& opand::traitement(litterale& a, litterale& b)
{

    littnumber* num1 = dynamic_cast<littnumber*>(&a);
    littnumber* num2 = dynamic_cast<littnumber*>(&b);

    if (num1 != 0 && num2 != 0) {
        if (num1->isNull() == false && num2->isNull()==false) {
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