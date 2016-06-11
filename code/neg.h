#ifndef NEG_H
#define NEG_H


#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"

/**
  \class neg
  \brief La classe d'opérateur qui renvoye la valeur négative de la littérale
  (NEG)
 */
class neg : public operateur_numerique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur numerique
    neg():operateur_numerique(1,"NEG"){}
    litterale& traitement(litterale &a, litterale &b){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    litterale& traitement(litterale &a);
};


#endif // NEG_H
