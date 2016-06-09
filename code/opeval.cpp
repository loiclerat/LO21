#include "opeval.h"
#include "littprogramme.h"
#include "pile.h"
#include "controleur.h"

litterale& opeval::traitement(litterale& a)
{

    littProgramme* pg = dynamic_cast<littProgramme*>(&a);

    if (pg != 0) {
        QString final = pg->getStr();
        final = final.remove(0,1); //Retire 1 caractere , à partir du 0 eme caractere
        final = final.remove(final.length()-1,1);
        Controleur& ctrl = Controleur::getInstance();
        ctrl.commande(final);
        Pile& p = ctrl.getterPile();
        litterale& res = p.top();
        p.pop();
        return res;
    }
    else {
        throw ComputerException("Ce n'est pas un nombre!");
    }
}
