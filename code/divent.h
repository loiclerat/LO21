#ifndef DIVENT_H
#define DIVENT_H

#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"

/**
  \class divent
  \brief La classe d'opérateur qui renvoye le résultat de la division entière de 2 litterales entieres
  (DIV)
 */
class divent : public operateur_numerique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur numerique
    divent():operateur_numerique(2,"DIV"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
};

#endif // DIVENT_H
