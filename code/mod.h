#ifndef MOD_H
#define MOD_H


#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"


class mod : public operateur_numerique
{
public:
    mod(QString s):operateur_numerique(2,s){}
    litterale& traitement(litterale &a, litterale &b);
};

#endif // MOD_H
