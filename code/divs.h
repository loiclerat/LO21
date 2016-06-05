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
public:
    divs(QString s):operateur_numerique(2,s){}
    litterale& traitement(litterale &a, litterale &b);
};

#endif // DIV_H
