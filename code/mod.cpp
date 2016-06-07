#include "mod.h"

litterale& mod::traitement(litterale &a, litterale &b){

    littEntiere* ent1 = dynamic_cast<littEntiere*>(&a);
    littNumerique* ent2 = dynamic_cast<littNumerique*>(&b);

    if(ent1 != 0 && ent2!=0)
    {
            littNumerique* res =  (*(ent1)/ent2);
            littrat* rat1 = dynamic_cast<littrat*>(res);
                if(rat1 != 0){
                    littEntiere* resf = new littEntiere(ent1->getValeur()%rat1->getDen());
                    return *resf;
                }
                else{
                    throw ComputerException("Format incompatible du second argument, nécessite entier");
                }
        }else {
            throw ComputerException("Format incompatible du second argument, nécessite entier");

        }
}
