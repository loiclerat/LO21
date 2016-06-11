#include "den.h"



litterale& den::traitement(litterale &a){

    littrat* rat = dynamic_cast<littrat*>(&a);
    littEntiere* ent = dynamic_cast<littEntiere*>(&a);

    if(rat != 0)
    {
        littEntiere* t = new littEntiere(rat->getDen());
        return *t;
    }else if(ent!=0){
        littEntiere* t = new littEntiere(1);
        return *t;
    }

    throw ComputerException("Cet objet n'a pas de dénominateur (réelle ou complexe)");
}
