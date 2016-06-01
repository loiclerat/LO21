#include "add.h"


litterale& add::traitement(litterale &a, litterale &b){
    littrat& e = dynamic_cast<littrat&>(a);
    littrat& f = dynamic_cast<littrat&>(b);

    littrat& res = e+f;
    return(res);
}
