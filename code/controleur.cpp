#include "controleur.h"
#include "exceptions.h"

void Controleur::commande(const QString& c){

    // analyse c -> litterale ou operateur
    // si litterale : quel type ? -> addLitterale
    // si operateur : lequel ? (iterateur pour trouver l'operateur correspondant au symbol c -> traitement()
    // setMessage...

    // Gestion de la pile dans le controlleur

    // Dépilement selon arité
    // appel de traitement avec les valeurs
    // création d'une litterale dans traitement puis retour de ref
    // empilement de la ref

    operateur* op;

    if (estLitterale(c)=="entiere"){
        littAff.push(littMng.addLitterale(c.toInt()));
    }
    else if ((op = estOperateur(c)) != 0){
        if (op->getArite()==1){
            if (littAff.taille()>=1)
                litterale& v = littAff.top();
                littAff.pop();
                littAff.push(op->traitement(littMng, v));
            else littAff.setMessage("Erreur : pas assez d'arguments");
        }
        else if(op->getArite()==2){
            if (littAff.taille()>=2)
                litterale& v1 = littAff.top();
                littAff.pop();
                litterale& v1 = littAff.top();
                littAff.pop();
                littAff.push(op->traitement(littMng, v1, v2));
            else littAff.setMessage("Erreur : pas assez d'arguments");
        }
    }
    else littAff.setMessage("Erreur : commande inconnue");

}

operateur* Controleur::estOperateur(const QString s){
    for(operateurManager::const_iterator it=opeMng.begin(); it!=opeMng.end(); ++it)
            if (s==(*it).getSymbol())   return &(*it);
    return 0;
}

QString estLitterale(const QString s){

    bool ok=false;
    c.toInt(&ok);
    if (ok) return "entiere";
}
