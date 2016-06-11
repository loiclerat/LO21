#include "den.h"



litterale& den::traitement(litterale &a){

    littrat* b = dynamic_cast<littrat*>(&a);

    if(b != 0)
    {
        littEntiere* t = new littEntiere(b->getDen());
        return *t;
        }else {
            throw ComputerException("Ce n'est pas une litterale qui peut être mise en négatif");

        }
}
