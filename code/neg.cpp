#include "neg.h"

litterale& neg::traitement(litteraleManager& mng, litterale &a){

    littnumber* b = dynamic_cast<littnumber*>(&a);
    littEntiere x(-2);

    if(b != nullptr)
    {
        littnumber* res = x*b;
        return mng.addLitterale(res);
        }else {
            throw ComputerException("Ce n'est pas un nombre!");

        }
}
