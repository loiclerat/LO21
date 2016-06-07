#ifndef OPRE_H
#define OPRE_H

#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"


class opre : public operateur_numerique
{
public:
    opre():operateur_numerique(1,"RE"){}
    litterale& traitement(litterale &a, litterale &b){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    litterale& traitement(litterale &a);
};


#endif // OPRE_H
