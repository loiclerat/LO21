#ifndef OPEBINAIRE_H
#define OPEBINAIRE_H
#include"litterale.h"


class binaire{
public :
virtual litterale& traitement(litterale& a, litterale& b)=0;
};

#endif // OPEBINAIRE_H
