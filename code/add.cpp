#include "add.h"
#include "exceptions.h"





litterale& add::traitement(litteraleManager& mng, litterale &a, litterale &b){


    littEntiere* ent1 = dynamic_cast<littEntiere*>(&a);
    littrat* rat1 = dynamic_cast<littrat*>(&a);
    littReelle* ree1 = dynamic_cast<littReelle*>(&a);
    littcomplexe* comp1 = dynamic_cast<littcomplexe*>(&a);

    littNumerique* lta1 = dynamic_cast<littNumerique*>(&b);
    littcomplexe* lta2 = dynamic_cast<littcomplexe*>(&b);

    if(ent1 != 0){
        if(lta1!=0){
            littNumerique* res =  *(ent1)+lta1;
            return mng.addLitterale(res);
        }
        else{
            littnumber* res = *(ent1)+lta2;
            return mng.addLitterale(res);
        }
    }
    else
        if(rat1 != 0)
        {
            if(lta1!=0){
                littNumerique* res =  *(rat1)+lta1;
                return mng.addLitterale(res);
            }else{
                littnumber* res = *(rat1)+lta2;
                return mng.addLitterale(res);
            }
        }
        else
            if(ree1 != 0){
                if(lta1!=0){
                    littNumerique* res =  *(ree1)+lta1;
                    return mng.addLitterale(res);
                }else{
                    littnumber* res = *(ree1)+lta2;
                    return mng.addLitterale(res);
                }
            }
            else
                if(comp1 != 0){
                    if(lta1!=0){
                        littnumber* res =  *(comp1)+lta1;
                        return mng.addLitterale(res);
                    }else{
                        littnumber* res = *(comp1)+lta2;
                        return mng.addLitterale(res);
                    }
            }
                else{
                    throw ComputerException("Format incompatible du premier argument");
                }

    delete ent1;
    delete rat1;
    delete ree1;
    delete comp1;
    delete lta1;
    delete lta2;

}

