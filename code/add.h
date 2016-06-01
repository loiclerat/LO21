#ifndef ADD_H
#define ADD_H
#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"


class add : public operateur_numerique
{
    QString symbol;
public:
    add(QString s, int i);
    litterale& traitement(litterale &a, litterale &b);
};

#endif // ADD_H
