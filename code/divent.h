#ifndef DIVENT_H
#define DIVENT_H

#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"


class divent : public operateur_numerique{
public:
    divent():operateur_numerique(2, "DIV"){}
    litterale& traitement(litteraleManager& mng, litterale &a, litterale &b);
    litterale& traitement(litteraleManager& mng, litterale& a){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};

#endif // DIVENT_H
