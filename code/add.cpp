#include "add.h"
#include "exceptions.h"


litterale& add::traitement(litterale &a, litterale &b){


    littEntiere* ent1 = dynamic_cast<littEntiere*>(&a);
    littrat* rat1 = dynamic_cast<littrat*>(&a);
    littReelle* ree1 = dynamic_cast<littReelle*>(&a);

    littNumerique* ltb = dynamic_cast<littNumerique*>(&b);

    //si a est un entier et que ltb est bien une litterale numerique
    if(ent1 != nullptr && ltb != nullptr){
        littNumerique* res =  *(ent1)+ltb;
        return *res;
    }
    else
        if(rat1 != nullptr && ltb != nullptr)
        {
                littNumerique* res =  *(rat1)+ltb;
                return *res;
        }
        else
            if(ree1 != nullptr && ltb != nullptr){
                littNumerique* res =  *(ree1)+ltb;
                return *res;
            }
            else{
                throw ComputerException("Format reelle invalide");
            }

}
