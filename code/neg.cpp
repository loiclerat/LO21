#include "neg.h"

litterale& neg::traitement(litterale &a){

    littnumber* b = dynamic_cast<littnumber*>(&a);
    littEntiere x(-2);

    if(b != 0)
    {
        littnumber* res = x*b;
        return *res;
        }else {
            throw ComputerException("Ce n'est pas un nombre!");

        }
}
