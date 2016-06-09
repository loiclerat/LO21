#ifndef AOPERATEUR_H
#define AOPERATEUR_H
#include "littatome.h"

class aoperateur : public littatome
{
    aoperateur* pointeur;
public:
    aoperateur(QString a, aoperateur* b):littatome(a),pointeur(b){};
};

#endif // AOPERATEUR_H
