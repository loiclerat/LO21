#ifndef MOD_H
#define MOD_H


#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"
#include "opebinaire.h"


class mod : public operateur_numerique, public binaire
{
    QString symbol;
public:
    mod(QString s):symbol(s),operateur_numerique(2){}
    litterale& traitement(litterale &a, litterale &b);
};

#endif // MOD_H
