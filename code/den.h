#ifndef DEN_H
#define DEN_H


#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"

/**
  \class den
  \brief La classe d'opérateur qui renvoye le dénominateur d'un litterale rationnelle ou un entier dans le cas litterale entière
  (DEN)
 */
class den : public operateur_numerique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur numerique
    den():operateur_numerique(1,"DEN"){}
    litterale& traitement(litterale &a, litterale &b){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    litterale& traitement(litterale &a);
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};



#endif // DEN_H
