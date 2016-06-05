#ifndef OPDIFF_H
#define OPDIFF_H


#include <QString>
#include "operateur_logique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"


class opdiff : public operateur_logique
{
public:
    opdiff():operateur_logique(2,"!="){}
    litterale& traitement(litteraleManager& mng, litterale &a, litterale &b);
    litterale& traitement(litteraleManager& mng, litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
};


#endif // OPDIFF_H
