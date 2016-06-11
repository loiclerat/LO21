#ifndef MOD_H
#define MOD_H


#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"


/**
  \class mod
  \brief La classe d'opérateur qui renvoye le résultat du modulo de 2 litterales
  (MOD)
 */

class mod : public operateur_numerique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur numerique
    mod():operateur_numerique(2,"MOD"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
};
#endif // MOD_H
