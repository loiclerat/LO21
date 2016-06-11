#include "opeval.h"
#include "littprogramme.h"
#include "pile.h"
#include "controleur.h"

litterale& opeval::traitement(litterale& a)
{
    qDebug()<<"ON ENTRE DANS LE EVAL avec pour argument : "<<a.affichage();
    littProgramme* pg = dynamic_cast<littProgramme*>(&a);

    if (pg != 0) {
        QString final = pg->getStr();
        final = final.remove(0,1); //Retire 1 caractere , à partir du 0 eme caractere
        final = final.remove(final.length()-1,1);
        Controleur& ctrl = Controleur::getInstance();
        Pile& p = ctrl.getterPile();
        p.pop();
        ctrl.commande(final);
        QStringList prog;
        prog = final.split('[', QString::SkipEmptyParts);
        if (prog.length() == 1) {
            litterale& res = p.top();
            return res;
        }
        else {
            litterale& res = p.top();
            for(unsigned int i=1; i<prog.length();i++){
                p.pop();
            }
            return res;

        }
    }
    else {
        throw ComputerException("Ce n'est pas un nombre!");
    }
}
