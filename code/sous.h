#ifndef SOUS_H
#define SOUS_H
#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"
#include "littcomplexe.h"


class sous : public operateur_numerique
{
    QString symbol;
public:
    sous(QString s):operateur_numerique(2,s){}
    litterale& traitement(litterale &a, litterale &b);
};

#endif // SOUS_H
