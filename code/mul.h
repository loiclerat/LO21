#ifndef MUL_H
#define MUL_H
#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"


class mul : public operateur_numerique
{
    QString symbol;
public:
    mul(QString s):symbol(s),operateur_numerique(2){}
    litterale& traitement(litterale &a, litterale &b);
};

#endif // MUL_H
