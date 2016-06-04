#include "add.h"
#include "exceptions.h"

litterale& add::traitement(litteraleManager& mng, litterale &a, litterale &b){

    // Création de pointeurs temporaires par downcasting
    // Cela nous permet par la suite de déterminer le type de littérale des paramètres
    littEntiere* a_ent = dynamic_cast<littEntiere*>(&a);

    littEntiere* b_ent = dynamic_cast<littEntiere*>(&b);

    // On vérifie le type des littérales passées en paramètre pour créer et renvoyer le bon type de littérale
    if(a_ent != 0){       // a est une litterale entiere
        if(b_ent!=0){     // b est une litterale entière
            littEntiere res(a_ent->getValeur()+b_ent->getValeur());
            return mng.addLitterale(res);
        }
    }

    // Gestion des erreurs

    // On désalloue les pointeurs temporaires
    delete a_ent;
    delete b_ent;

}
