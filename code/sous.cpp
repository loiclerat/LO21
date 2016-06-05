#include "sous.h"
#include "exceptions.h"


litterale& sous::traitement(litterale &a, litterale &b){


    littEntiere* ent1 = dynamic_cast<littEntiere*>(&a);
    littrat* rat1 = dynamic_cast<littrat*>(&a);
    littReelle* ree1 = dynamic_cast<littReelle*>(&a);
    littcomplexe* comp1 = dynamic_cast<littcomplexe*>(&a);

    littNumerique* lta1 = dynamic_cast<littNumerique*>(&b);
    littcomplexe* lta2 = dynamic_cast<littcomplexe*>(&b);

    //si a est un entier et que ltb est bien une litterale numerique
    if(ent1 != 0){
        if(lta1!=0){
            littNumerique* res =  *(ent1)-lta1;
            return *res;
        }
        else{
            littnumber* res = *(ent1)-lta2;
            return *res;
        }
    }
    else
        if(rat1 != 0)
        {
            if(lta1!=0){
                littNumerique* res =  *(rat1)-lta1;
                return *res;
            }else{
                littnumber* res = *(rat1)-lta2;
                return *res;
            }
        }
        else
            if(ree1 != 0){
                if(lta1!=0){
                    littNumerique* res =  *(ree1)-lta1;
                    return *res;
                }else{
                    littnumber* res = *(ree1)-lta2;
                    return *res;
                }
            }
            else
                if(comp1 != 0){
                    if(lta1!=0){
                        littnumber* res =  *(comp1)-lta1;
                        return *res;
                    }else{
                        littnumber* res = *(comp1)-lta2;
                        return *res;
                    }
            }
                else{
                    throw ComputerException("Format incompatible du premier argument");
                }

}

