#include "opift.h"
#include "controleur.h"
#include "opdup.h"

litterale& opIft::traitement(litterale& a, litterale& b)
{

    littEntiere* booleen = dynamic_cast<littEntiere*>(&a);
    littProgramme* prog = dynamic_cast<littProgramme*>(&b);

    qDebug()<<"PREMIER ARGUMENT "<<booleen->affichage();
    qDebug()<<"SECOND ARGUMENT "<<prog->affichage();

    if (booleen != 0 && prog != 0) {
        if(booleen->getValeur()==1){
            opeval* ope = new opeval();
            opdup* opee=new opdup();
            opee->traitement();
            litterale& a = ope->traitement(*prog);
            return a;
        }
        else
            throw ComputerException("La valeur est 0, on abandonne");
    }
    else {
        throw ComputerException("Format incompatible des argument, nécessite un nombre et un programme");
    }
}
