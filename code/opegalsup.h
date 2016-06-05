#ifndef OPEGALSUP_H
#define OPEGALSUP_H

#include <QString>
#include "operateur_logique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"


class opegalsup : public operateur_logique
{
public:
    opegalsup(QString s):operateur_logique(2,">="){}
    litterale& traitement(litteraleManager& mng, litterale &a, litterale &b);
    litterale& traitement(litteraleManager& mng, litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
};



#endif // OPEGALSUP_H
