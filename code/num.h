#ifndef NUM_H
#define NUM_H


#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"


class num : public operateur_numerique
{
public:
    num(QString s):operateur_numerique(2,s){}
    litterale& traitement(litterale &a);
};
#endif // NUM_H
