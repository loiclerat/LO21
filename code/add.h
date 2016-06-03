#ifndef ADD_H
#define ADD_H
#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"


class add : public operateur_numerique
{
    QString symbol;
public:
    add(QString s):symbol(s),operateur_numerique(2){};
    litterale& traitement(litterale &a, litterale &b);
};

#endif // ADD_H
