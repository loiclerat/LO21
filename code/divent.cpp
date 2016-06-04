#include "divent.h"

litterale& divent::traitement(litterale &a, litterale &b){

    littEntiere* ent1 = dynamic_cast<littEntiere*>(&a);
    littNumerique* ent2 = dynamic_cast<littNumerique*>(&b);

    if(ent1 != nullptr && ent2!=nullptr)
    {
            littNumerique* res =  (*(ent1)/ent2);
            littrat* rat1 = dynamic_cast<littrat*>(res);
                if(rat1 != nullptr){
                    int a = rat1->getNum()/rat1->getDen();
                    littEntiere* resf = new littEntiere(a);
                    return *resf;
                }
                else{
                    throw ComputerException("Format incompatible du second argument, nécessite entier");
                }
        }else {
            throw ComputerException("Format incompatible du second argument, nécessite entier");

        }
}
