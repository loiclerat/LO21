#include "opdup.h"
#include "controleur.h"
void opdup::traitement(){
        Controleur& ctrl = Controleur::getInstance();
        Pile& pile = ctrl.getterPile();
        litterale& adup = pile.top();
        litterale& ret = adup;
        pile.push(ret);
        return 0;
}
