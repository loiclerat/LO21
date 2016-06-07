#ifndef OPNOT_H
#define OPNOT_H

#include <QString>
#include "operateur_logique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"


class opnot : public operateur_logique
{
public:
    opnot():operateur_logique(2,"NOT"){}
    litterale& traitement(litterale &a, litterale &b){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    litterale& traitement(litterale &a);
};
#endif // OPNOT_H
