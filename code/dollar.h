#ifndef DOLLAR_H
#define DOLLAR_H


#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"


class dollar : public operateur_numerique
{
public:
    dollar(QString s):operateur_numerique(2,s){}
    litterale& traitement(litteraleManager& mng, litterale &a, litterale &b);
    litterale& traitement(litteraleManager& mng, litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
};


#endif // DOLLAR_H
