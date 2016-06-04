#include "mul.h"
#include "exceptions.h"


litterale& mul::traitement(litterale &a, litterale &b){

    littEntiere* ent1 = dynamic_cast<littEntiere*>(&a);
    littrat* rat1 = dynamic_cast<littrat*>(&a);
    littReelle* ree1 = dynamic_cast<littReelle*>(&a);
    littcomplexe* comp1 = dynamic_cast<littcomplexe*>(&a);

    littNumerique* lta1 = dynamic_cast<littNumerique*>(&b);
    littcomplexe* lta2 = dynamic_cast<littcomplexe*>(&b);

    //si a est un entier et que ltb est bien une litterale numerique
    if(ent1 != nullptr){
        if(lta1!=nullptr){
            littNumerique* res =  *(ent1)*lta1;
            return *res;
        }
        else{
            littnumber* res = *(ent1)*lta2;
            return *res;
        }
    }
    else
        if(rat1 != nullptr)
        {
            if(lta1!=nullptr){
                littNumerique* res =  *(rat1)*lta1;
                return *res;
            }else{
                littnumber* res = *(rat1)*lta2;
                return *res;
            }
        }
        else
            if(ree1 != nullptr){
                if(lta1!=nullptr){
                    littNumerique* res =  *(ree1)*lta1;
                    return *res;
                }else{
                    littnumber* res = *(ree1)*lta2;
                    return *res;
                }
            }
            else
                if(comp1 != nullptr){
                    if(lta1!=nullptr){
                        littnumber* res =  *(comp1)*lta1;
                        return *res;
                    }else{
                        littnumber* res = *(comp1)*lta2;
                        return *res;
                    }
            }
                else{
                    throw ComputerException("Format incompatible du premier argument");
                }

}
litterale& mul::traitement(litterale& a){

}