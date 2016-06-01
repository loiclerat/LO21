#ifndef AOPERATEUR_H
#define AOPERATEUR_H
#include "littatome.h"

class aoperateur : public littatome
{
    aoperateur* opa;
public:
    aoperateur(QString a, aoperateur* b):littatome(a),opa(b){};
};

#endif // AOPERATEUR_H
