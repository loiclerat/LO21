#include "opnot.h"

litterale& opnot::traitement(litterale& a)
{
    littnumber* num1 = dynamic_cast<littnumber*>(&a);
    qDebug()<<"on est dans NOT= "<<num1->affichage();

    if (num1 != 0) {
        qDebug()<<"on a un number = "<<num1->affichage();
        if (num1->isNull()==true) {
            littEntiere* ret = new littEntiere(1);
            return *ret;

            qDebug()<<"NOT doit valoir 1 = "<<num1->affichage();
        }
        else {

            qDebug()<<"NOT doit valoir 0  = "<<num1->affichage();
            littEntiere* ret = new littEntiere(0);
            return *ret;
        }
    }
    else {
        throw ComputerException("Format incompatible des argument, nécessite un nombre");
    }

}
