#ifndef OPINF_H
#define OPINF_H

#include <QString>
#include "operateur_logique.h"
#include "litterale.h"
#include "littrat.h"
#include "littentiere.h"
#include "littreelle.h"

/**
  \class opinf
  \brief La classe d'opérateur qui renvoye le résultat de la comparaison par le signe inférieur
  (<)
 */

class opinf : public operateur_logique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur logique
    opinf():operateur_logique(2,"<"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};

#endif // OPINF_H
