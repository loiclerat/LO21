#include "opsup.h"

litterale& opsup::traitement(litterale& a, litterale& b)
{

    littnumber* num1 = dynamic_cast<littnumber*>(&a);
    littnumber* num2 = dynamic_cast<littnumber*>(&b);

    if (num1 != 0 && num2 != 0) {
        littnumber* res = (*(num1)-num2);
        if (res->isPos() == true) {
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
