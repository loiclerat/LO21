#ifndef OPIM_H
#define OPIM_H


#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"

/**
  \class opim
  \brief La classe d'opérateur qui renvoye la partie imaginaire de la litterale complexe
  (IM)
 */

class opim : public operateur_numerique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur numerique
    opim():operateur_numerique(1,"IM"){}
    litterale& traitement(litterale &a, litterale &b){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    litterale& traitement(litterale &a);
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};


#endif // OPIM_H
