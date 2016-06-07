/**
\file item.cpp
\date 03/06/2016
\author LoÃƒÂ¯c Lerat, AndrÃƒÂ©a Vibert, ThÃƒÂ©o Hordequin
\version 1.0
\brief  DÃ©finition des mÃ©thodes de la classe Controleur


**/


#include "controleur.h"
#include "exceptions.h"
#include <QStringList>


operateur* Controleur::estOperateur(const QString s){

    for(operateurManager::const_iterator it=opeMng.begin_const(); it!=opeMng.end_const(); ++it){
        qDebug()<<(*it).getSymbol();
        if ((*it).getSymbol() == s)   return &(*it);
    }
    return 0;
}


//! \brief Retourne une chaine de caractère correspondant au type de littérale que le manager de littérales devra créer ou une chaine de caractère nulle s'il ne reconnaît pas la suite de symboles entrés
QString Controleur::estLitterale(const QString s){

    bool ok=false;
    if(s.toInt(&ok) || s=="0") return "entiere";//! \brief Test pour voir s'il s'agit d'une littEntiere
    else {
        if(s.toFloat(&ok)) return "reelle"; //! \brief Test pour voir s'il s'agit d'une littReelle
        else return "";
    }
}

void Controleur::commande(const QString& c){

    // analyse c -> litterale ou operateur
    // si litterale : quel type ? -> addLitterale
    // si operateur : lequel ? (iterateur pour trouver l'operateur correspondant au symbol c -> traitement()
    // setMessage...

    // Gestion de la pile dans le controlleur

    // DÃ©pilement selon aritÃ©
    // appel de traitement avec les valeurs
    // crÃ©ation d'une litterale dans traitement puis retour de ref
    // empilement de la ref

    operateur* op;

    if (estLitterale(c)!=""){
        if (estLitterale(c)=="entiere"){
            littEntiere* l=new littEntiere(c.toInt());
            littAff.push(*l);
        }
        else {
            if (estLitterale(c)=="reelle"){
                QStringList list = c.split(".");
                QString ent=list[0]; QString dec=list[1];
                if (dec=="") {
                    littEntiere* l=new littEntiere(ent.toInt());
                    littAff.push(*l);
                }
                else {
                    littReelle* l=new littReelle(ent.toInt(),c.toFloat()-ent.toInt());
                    littAff.push(*l);
                }
            }
        }
    }
    else if ((op = estOperateur(c)) != 0){
        if (op->getArite()==1){
            if (littAff.taille()>=1){
                litterale& v = littAff.top();
                littAff.pop();
                littAff.push(op->traitement(v));
            }
            else littAff.setMessage("Erreur : pas assez d'arguments");
        }
        else if(op->getArite()==2){
            if (littAff.taille()>=2){
                litterale& v1 = littAff.top();
                littAff.pop();
                litterale& v2 = littAff.top();
                littAff.pop();
                littAff.push(op->traitement(v2, v1));
            }
            else littAff.setMessage("Erreur : pas assez d'arguments");
        }
    }
    else littAff.setMessage("Erreur : commande inconnue");


}

