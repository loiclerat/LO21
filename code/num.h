#ifndef NUM_H
#define NUM_H



#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"

/**
  \class num
  \brief La classe d'opérateur qui renvoye la valeur du numerateur de la littérale
  (NEG)
 */

class num : public operateur_numerique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur numerique
    num():operateur_numerique(1,"NUM"){}
    litterale& traitement(litterale &a, litterale &b){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    litterale& traitement(litterale &a);
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};



#endif // NUM_H
