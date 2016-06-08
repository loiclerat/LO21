#include "littnumber.h"
#include "littentiere.h"

littnumber* littNumerique::operator-(littnumber* a){
    littEntiere* ent = dynamic_cast<littEntiere*>(this);
    littrat* rat = dynamic_cast<littrat*>(this);
    littReelle* ree = dynamic_cast<littReelle*>(this);

    if(ent != 0){
        littnumber* res = *(ent)-a;
        return res;
    }
    else
        if(rat != 0){
            littnumber* resf = *(rat)-a;
            return resf;
        }
    else
            if(ree != 0){
                littnumber* resff = *(ree)-a;
                return resff;
            }
            else{
                throw ComputerException("operation impossible");
    }
}
