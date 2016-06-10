#ifndef ALITT_H
#define ALITT_H
#include "littatome.h"
#include "litterale.h"


class aLitt : public littatome
{
    litterale* operande;
public:
    aLitt(QString a, litterale* b):littatome(a,b){}
};

#endif // ALITT_H
