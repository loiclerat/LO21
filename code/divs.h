#ifndef DIV_H
#define DIV_H

#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"


class divs : public operateur_numerique
{
    QString symbol;
public:
    divs(QString s):symbol(s),operateur_numerique(2){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a);
};

#endif // DIV_H
