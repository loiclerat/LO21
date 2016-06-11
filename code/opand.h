#ifndef OPAND_H
#define OPAND_H


#include <QString>
#include "operateur_logique.h"
#include "litterale.h"

/**
  \class opand
  \brief La classe d'opérateur qui renvoye la resultat de l'opérateur AND
  (AND)
 */

class opand : public operateur_logique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur logique
    opand():operateur_logique(2,"AND"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};


#endif // OPAND_H
