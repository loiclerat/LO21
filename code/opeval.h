#ifndef OPEVAL_H
#define OPEVAL_H

#include <QString>
#include "litterale.h"
#include "operateur_numerique.h"


class opeval : public operateur_numerique
{
public:
    opeval():operateur_numerique(1,"EVAL"){}
    litterale& traitement(litterale &a, litterale &b){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    litterale& traitement(litterale &a);
};

#endif // OPEVAL_H
