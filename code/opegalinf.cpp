#include "opegalinf.h"

litterale& opegalinf::traitement(litteraleManager& mng, litterale& a, litterale& b)
{

    littnumber* num1 = dynamic_cast<littnumber*>(&a);
    littnumber* num2 = dynamic_cast<littnumber*>(&b);

    if (num1 != 0 && num2 != 0) {
        littnumber* res = (*(num1)-num2);
        if (res->isPos() == false || res->isNull() == true) {
            littEntiere ret(1);
            return mng.addLitterale(ret);
        }
        else {
            littEntiere ret(0);
            return mng.addLitterale(ret);
        }
    }
    else {
        throw ComputerException("Format incompatible des argument, nécessite un nombre");
    }
}