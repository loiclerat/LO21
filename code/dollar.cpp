#include "dollar.h"


litterale& dollar::traitement(litterale &a, litterale &b){

    littNumerique* lta1 = dynamic_cast<littNumerique*>(&a);
    littNumerique* lta2 = dynamic_cast<littNumerique*>(&b);

    if(lta1 != 0){
        if(lta2 != 0){
            littcomplexe* res = new littcomplexe(lta1,lta2);
            return *res;
        }
        else{
            throw ComputerException("Le second argument n'est pas une litterale numerique");
        }
    }
    else{
        throw ComputerException("Le premier argument n'est pas une litterale numerique");
    }

}
