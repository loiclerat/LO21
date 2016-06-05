#ifndef NUM_H
#define NUM_H


#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"


class num : public operateur_numerique{
public:
    num():operateur_numerique(2, "NUM"){}
    litterale& traitement(litteraleManager& mng, litterale &a, litterale &b){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
    litterale& traitement(litteraleManager& mng, litterale& a);
};

#endif // NUM_H
