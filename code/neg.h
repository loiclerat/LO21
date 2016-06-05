#ifndef NEG_H
#define NEG_H




#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"


class neg : public operateur_numerique
{
public:
    neg(QString s):operateur_numerique(1,s){}
    litterale& traitement(litteraleManager& mng, litterale &a, litterale &b){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    litterale& traitement(litteraleManager& mng, litterale &a);
};


#endif // NEG_H
