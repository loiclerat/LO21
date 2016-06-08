#ifndef ADD_H
#define ADD_H
#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"


class add : public operateur_numerique{
public:
    add():operateur_numerique(2,"+"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale& a){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};

#endif // ADD_H
