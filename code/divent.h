#ifndef DIVENT_H
#define DIVENT_H

#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"
#include "opebinaire.h"


class divent : public operateur_numerique, public binaire
{
    QString symbol;
public:
    divent(QString s):symbol(s),operateur_numerique(2){}
    litterale& traitement(litterale &a, litterale &b);
};


#endif // DIVENT_H
