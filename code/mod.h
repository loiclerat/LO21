#ifndef MOD_H
#define MOD_H


#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"


class mod : public operateur_numerique{
public:
    mod():operateur_numerique(2, "%"){}
    litterale& traitement(litteraleManager& mng, litterale &a, litterale &b);
    litterale& traitement(litteraleManager& mng, litterale& a){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};
#endif // MOD_H