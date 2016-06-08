#ifndef OPSUP_H
#define OPSUP_H

#include <QString>
#include "operateur_logique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"


class opsup : public operateur_logique
{
public:
    opsup():operateur_logique(2,">"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
};

#endif // OPSUP_H
