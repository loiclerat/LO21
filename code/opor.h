#ifndef OPOR_H
#define OPOR_H

#include <QString>
#include "operateur_logique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"

/**
  \class opor
  \brief La classe d'opérateur qui renvoye le résultat de la comparaison par l'opérateur OR
  (OR)
 */

class opor : public operateur_logique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur logique
    opor():operateur_logique(2,"OR"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
};


#endif // OPOR_H
