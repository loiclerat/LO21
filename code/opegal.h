#ifndef OPEGAL_H
#define OPEGAL_H


#include <QString>
#include "operateur_logique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"


class opegal : public operateur_logique
{
public:
    opegal():operateur_logique(2,"="){}
    litterale& traitement(litteraleManager& mng, litterale &a, litterale &b);
    litterale& traitement(litteraleManager& mng, litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
};



#endif // OPEGAL_H
