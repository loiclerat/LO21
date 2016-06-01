#ifndef AOPERATEUR_H
#define AOPERATEUR_H
#include "littatome.h"

class aoperateur : public littatome
{
    operateur* opa;
public:
    aoperateur(QString a, operateur* b):littatome(a),opa(b){};
};

#endif // AOPERATEUR_H
