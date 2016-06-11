#ifndef OPEGALSUP_H
#define OPEGALSUP_H

#include <QString>
#include "operateur_logique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"

/**
  \class opegalsup
  \brief La classe d'opérateur qui renvoye la resultat de l'opérateur supérieur ou égale
  (>=)
 */

class opegalsup : public operateur_logique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur logique
    opegalsup():operateur_logique(2,">="){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};



#endif // OPEGALSUP_H
