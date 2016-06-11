#ifndef OPDUP_H
#define OPDUP_H

#include <QString>
#include "operateur_pile.h"
#include "litterale.h"


/**
  \class opdup
  \brief La classe d'opérateur qui renvoye la resultat de l'opérateur duplication
  (DUP)
 */

class opdup : public operateur_pile
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur logique
    opdup():operateur_pile(0,"DUP"){}
    litterale& traitement(litterale &a, litterale &b){
    throw ComputerException("Arité incorrecte pour cet opérateur");
    }
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    void traitement();
};


#endif // OPDUP_H
