#ifndef DOLLAR_H
#define DOLLAR_H


#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"

/**
  \class dollar
  \brief La classe d'opérateur qui renvoye une littérale complexe formée des 2 litterales dépilées
  ($)
 */
class dollar : public operateur_numerique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur numerique
    dollar():operateur_numerique(2,"$"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};


#endif // DOLLAR_H
