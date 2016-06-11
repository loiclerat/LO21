#ifndef OPEVAL_H
#define OPEVAL_H

#include <QString>
#include "litterale.h"
#include "operateur_numerique.h"

/**
  \class opeval
  \brief La classe d'opérateur qui renvoye la resultat de l'évaluation de la litterale programme
  (EVAL)
 */

class opeval : public operateur_numerique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur numerique
    opeval():operateur_numerique(1,"EVAL"){}
    litterale& traitement(litterale &a, litterale &b){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    litterale& traitement(litterale &a);
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};

#endif // OPEVAL_H
