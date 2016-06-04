#ifndef NEG_H
#define NEG_H




#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"
#include "opeunaire.h"


class neg : public operateur_numerique, public unaire
{
    QString symbol;
public:
    neg(QString s):symbol(s),operateur_numerique(2){}
    litterale& traitement(litterale &a);
};


#endif // NEG_H
