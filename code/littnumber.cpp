#include "littnumber.h"
#include "littcomplexe.h"

littnumber* littnumber::operator-(littnumber* a){
    littcomplexe* comp = dynamic_cast<littcomplexe*>(this);
    littNumerique* num = dynamic_cast<littNumerique*>(this);

    if(comp != 0){
        littnumber* res = *(comp)-a;
        return res;
    }
    else
        if(num != 0){
            littnumber* resf = *(num)-a;
            return resf;
        }
    return 0;
}
