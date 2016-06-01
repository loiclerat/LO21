#ifndef ALITT_H
#define ALITT_H
#include "littatome.h"
#include "litterale.h"


class aLitt : public littatome
{
    litterale* litt;
public:
    aLitt(QString a, litterale* b):littatome(a),litt(b){}
};

#endif // ALITT_H
