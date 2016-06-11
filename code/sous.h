#ifndef SOUS_H
#define SOUS_H
#include <QString>
#include "operateur_numerique.h"
#include "litterale.h"

/**
  \class sous
  \brief La classe d'opérateur qui effectue l'addition entre 2 littérales
  (+)
 */
class sous : public operateur_numerique{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur numerique
    sous():operateur_numerique(2,"-"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};


#endif // SOUS_H
