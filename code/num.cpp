#include "num.h"



litterale& num::traitement(litteraleManager& mng, litterale &a){

    littrat* b = dynamic_cast<littrat*>(&a);
    littEntiere *c=dynamic_cast<littEntiere*>(&a);

    if(b != 0)
    {
        littEntiere* t =  new littEntiere(b->getNum());
        return mng.addLitterale(t);
    }
    else{
        if(c!=0){
            littEntiere* t =  new littEntiere(c->getValeur());
            return mng.addLitterale(t);
        }
        else throw ComputerException("On ne peut pas retourner le numérateur de cette littérale.");
    }
}

