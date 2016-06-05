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
    neg(QString s):operateur_numerique(2,s){}
    litterale& traitement(litterale &a);
};


#endif // NEG_H
