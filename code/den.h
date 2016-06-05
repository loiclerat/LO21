#ifndef DEN_H
#define DEN_H



#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"


class den : public operateur_numerique
{
public:
    den(QString s):operateur_numerique(1,s){}
    litterale& traitement(litteraleManager& mng, litterale &a, litterale &b){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    litterale& traitement(litteraleManager& mng, litterale &a);
};



#endif // DEN_H
