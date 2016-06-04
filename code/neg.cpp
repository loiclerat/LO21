#include "neg.h"

litterale& neg::traitement(litterale &a){

    littnumber* b = dynamic_cast<littnumber*>(&a);

    if(b != nullptr)
    {
        b->NEG();
        return *b;
        }else {
            throw ComputerException("Ce n'est pas un nombre!");

        }
}
