#include "neg.h"

litterale& neg::traitement(litteraleManager& mng, litterale &a){

    littnumber* b = dynamic_cast<littnumber*>(&a);

    if(b != nullptr)
    {
        b->NEG();
        return mng.addLitterale(b);
        }else {
            throw ComputerException("Ce n'est pas un nombre!");

        }
}
