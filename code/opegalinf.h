#ifndef OPEGALINF_H
#define OPEGALINF_H

#include <QString>
#include "operateur_logique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"

/**
  \class opegalinf
  \brief La classe d'opérateur qui renvoye la resultat de l'opérateur inférieur ou égale
  (=<)
 */

class opegalinf : public operateur_logique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur logique
    opegalinf():operateur_logique(2,"=<"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};


#endif // OPEGALINF_H
