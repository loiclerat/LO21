#ifndef OPIFT_H
#define OPIFT_H


#include <QString>
#include "litterale.h"
#include "operateur_conditionnel.h"
#include "littprogramme.h"
#include "littentiere.h"
#include "opeval.h"

/**
  \class opIft
  \brief La classe d'opérateur conditionnel IFT. Si le 1er argument (dernier dépilé) est 1, on execute le programme, sinon on abandonne
 */

class opIft : public operateur_conditionnel
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur conditionnel
    opIft():operateur_conditionnel(2,"IFT"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
};


#endif // OPIFT_H
