#ifndef NUM_H
#define NUM_H


#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"
#include "opeunaire.h"


class num : public operateur_numerique, public unaire
{
    QString symbol;
public:
    num(QString s):symbol(s),operateur_numerique(2){}
    litterale& traitement(litterale &a);
};
#endif // NUM_H
