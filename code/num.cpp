#include "num.h"



litterale& num::traitement(litteraleManager& mng, litterale &a){

    littrat* b = dynamic_cast<littrat*>(&a);

    if(b != 0)
    {
        littEntiere t(b->getNum());
        return mng.addLitterale(&t);
        }else {
            throw ComputerException("Ce n'est pas une litterale rationnelle");

        }
}

