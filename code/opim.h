#ifndef OPIM_H
#define OPIM_H


#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"


class opim : public operateur_numerique
{
public:
    opim():operateur_numerique(1,"IM"){}
    litterale& traitement(litteraleManager& mng, litterale &a, litterale &b){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    litterale& traitement(litteraleManager& mng, litterale &a);
};


#endif // OPIM_H
