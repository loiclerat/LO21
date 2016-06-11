#ifndef ADD_H
#define ADD_H
#include <QString>
#include "exceptions.h"
#include "operateur_numerique.h"
#include "litterale.h"
/**
  \class add
  \brief La classe d'opérateur qui effectue l'addition entre 2 littérales
  (+)
 */
class add : public operateur_numerique{
public:

    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur numerique
    add():operateur_numerique(2,"+"){}

    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale& a){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};

#endif // ADD_H
