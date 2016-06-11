#ifndef DIV_H
#define DIV_H

#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"
#include "littcomplexe.h"

/**
  \class divs
  \brief La classe d'opérateur qui renvoye le résultat de la division de 2 litterales
  (/)
 */
class divs : public operateur_numerique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur numerique
    divs():operateur_numerique(2,"/"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};

#endif // DIV_H
