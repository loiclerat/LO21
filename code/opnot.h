#ifndef OPNOT_H
#define OPNOT_H

#include <QString>
#include "operateur_logique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"

/**
  \class opnot
  \brief La classe d'opérateur qui renvoye le résultat de la comparaison par l'opérateur NOT
  (NOT)
 */

class opnot : public operateur_logique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur logique
    opnot():operateur_logique(1,"NOT"){}
    litterale& traitement(litterale &a, litterale &b){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    litterale& traitement(litterale &a);
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};
#endif // OPNOT_H
