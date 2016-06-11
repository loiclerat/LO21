#ifndef OPDIFF_H
#define OPDIFF_H


#include <QString>
#include "operateur_logique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"


/**
  \class opdiff
  \brief La classe d'opérateur qui renvoye la resultat de l'opérateur différent
  (!=)
 */

class opdiff : public operateur_logique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur logique
    opdiff():operateur_logique(2,"!="){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
};


#endif // OPDIFF_H
