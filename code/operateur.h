#ifndef OPERATEUR_H
#define OPERATEUR_H
#include "litterale.h"

class operateur {
protected:
    int arite;
public:
    operateur(int a):arite(a){};
    int getArite(){return arite;}
};

#endif // OPERATEUR_H
