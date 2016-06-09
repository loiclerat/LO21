#ifndef ALITT_H
#define ALITT_H
#include "littatome.h"
#include "litterale.h"


class aLitt : public littatome
{
    litterale* pointeur;
public:
    aLitt(QString a, litterale* b):littatome(a),pointeur(b){}
};

#endif // ALITT_H
