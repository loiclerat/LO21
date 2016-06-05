#include "opegal.h"

litterale& opegal::traitement(litteraleManager& mng, litterale &a, litterale &b){

    littnumber* num1 = dynamic_cast<littnumber*>(&a);
    littnumber* num2 = dynamic_cast<littnumber*>(&b);

    if(num1 != 0 && num1!=0)
    {
            littNumerique* res =  (*(ent1)/ent2);
            littrat* rat1 = dynamic_cast<littrat*>(res);
                if(rat1 != 0){
                    littEntiere* resf = new littEntiere(ent1->getValeur()%rat1->getDen());
                    return mng.addLitterale(resf);
                }
                else{
                    throw ComputerException("Format incompatible du second argument, nécessite un nombre");
                }
        }else {
            throw ComputerException("Format incompatible du second argument, nécessite un nombre");

        }
}
