#ifndef OPEGALINF_H
#define OPEGALINF_H

#include <QString>
#include "operateur_logique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"


class opegalinf : public operateur_logique
{
public:
    opegalinf(QString s):operateur_logique(2,"=<"){}
    litterale& traitement(litteraleManager& mng, litterale &a, litterale &b);
    litterale& traitement(litteraleManager& mng, litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
};


#endif // OPEGALINF_H
