#include "opinf.h"

litterale& opinf::traitement(litterale& a, litterale& b)
{

    qDebug()<<"LE A VAUT : "<<a.affichage();
    qDebug()<<"LE B VAUT : "<<b.affichage();
    littnumber* num1 = dynamic_cast<littnumber*>(&a);
    littnumber* num2 = dynamic_cast<littnumber*>(&b);

    if (num1 != 0 && num2 != 0) {
        littnumber* res = (*(num1)-(num2));
        if (res->isPos() == false && res->isNull() == false ) {
            littEntiere* ret = new littEntiere(1);
            return *ret;
        }
        else {
            littEntiere* ret = new littEntiere(0);
            return *ret;
        }
    }
    else {
        throw ComputerException("Format incompatible des arguments, nécessite deux nombres");
    }
}
