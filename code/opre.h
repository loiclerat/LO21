#ifndef OPRE_H
#define OPRE_H

#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"

/**
  \class opre
  \brief La classe d'opérateur qui renvoye la partie réelle de la litterale complexe
  (RE)
 */

class opre : public operateur_numerique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur numerique
    opre():operateur_numerique(1,"RE"){}
    litterale& traitement(litterale &a, litterale &b){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    litterale& traitement(litterale &a);
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};


#endif // OPRE_H
