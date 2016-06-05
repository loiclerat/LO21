#include "den.h"



litterale& den::traitement(litteraleManager& mng, litterale &a){

    littrat* b = dynamic_cast<littrat*>(&a);

    if(b != nullptr)
    {
        littEntiere t(b->getDen());
        return mng.addLitterale(&t);
        }else {
            throw ComputerException("Ce n'est pas une litterale rationnelle");

        }
}

