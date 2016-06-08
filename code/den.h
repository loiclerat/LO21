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
    den():operateur_numerique(1,"DEN"){}
    litterale& traitement(litterale &a, litterale &b){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    litterale& traitement(litterale &a);
};



#endif // DEN_H
