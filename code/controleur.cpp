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

Controleur::Controleur(operateurManager& o, Pile& v):littAff(v), opeMng(o), careTaker(), history_index(0){
    QRegExp rx("^[A-Z]([A-Z]|[0-9])*");
    for(operateurManager::iterator it=opeMng.begin(); it!=opeMng.end(); ++it){
        if (rx.exactMatch((*it).getSymbol())) mapAtome.insert((*it).getSymbol(), &(*it));
    }
    save();
}

operateur* Controleur::estOperateur(const QString s){

    for(operateurManager::const_iterator it=opeMng.begin_const(); it!=opeMng.end_const(); ++it){
        if ((*it).getSymbol() == s)   return &(*it);
    }
    return 0;
}

QString Controleur::estLitteraleAtome(const QString s){
   /*/ QRegExp rx("^[A-Z]([A-Z]|[0-9])*");
    if(rx.exactMatch(s)) return s; // ici �a devrait retourner l'intitule de la litterale/de l'operateur/du programme dans l'atome manager
    else return "";*/

    operande* resRecherche= mapAtome.value(s,0);
    if(resRecherche) return mapAtome[s];
    else return 0;

}

//! \brief Retourne une chaine de caractère correspondant au type de littérale que le manager de littérales devra créer ou une chaine de caractère nulle s'il ne reconnaît pas la suite de symboles entrés
QString Controleur::estLitterale(const QString s){

    bool ok=false;


        s.toInt(&ok);
        if(ok) return "entiere";//! \brief Test pour voir s'il s'agit d'une littEntiere

        else {
            s.toFloat(&ok);
            if(ok) return "reelle"; //! \brief Test pour voir s'il s'agit d'une littReelle
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
    littAff.setMessage("");
    operateur* op;
try{

        if(estLitteraleAtome(c)){
            operateur* ope = dynamic_cast<operateur*>(c);
            litterale* litt = dynamic_cast<litterale*>(c);

            if(ope) c=ope->getSymbol();
            else if (litt) c=litt->affichage();
        }

    if (!estLitterale(c).isEmpty()){
        if (estLitterale(c)=="entiere"){
            littEntiere* l=new littEntiere(c.toInt());
            littAff.push(*l);
        }
        else {
            if (estLitterale(c)=="reelle"){
                QStringList list = c.split(".");
                QString ent=list[0]; QString dec=list[1];
                if (dec=="") {
                    littEntiere* l=new littEntiere(ent.toInt());// forge le int sur un
                    littAff.push(*l);
                }
                else {
                    littReelle* l=new littReelle(ent.toInt(),c.toFloat()-ent.toInt());
                    littAff.push(*l);
                }
            }
        }
        save();
    }
    else if ((op = estOperateur(c)) != 0){
        if (op->getArite()==1){
            if (littAff.taille()>=1){
                litterale& v = littAff.top();
                litterale* ptr=&(op->traitement(v));
                if (ptr!=0){
                    littAff.pop();
                    littAff.push(*ptr);
                }
                save();
            }
            else littAff.setMessage("Erreur : pas assez d'arguments");
        }
        else if(op->getArite()==2){
            if (littAff.taille()>=2){
                litterale& v1 = littAff.top();
                littAff.pop();
                litterale& v2 = littAff.top();
                littAff.pop();
                litterale* ptr=&(op->traitement(v2, v1));
                littAff.push(*ptr);
                save();
                if (ptr==0) loadPrecedent();
            }
            else littAff.setMessage("Erreur : pas assez d'arguments");
        }
    }
    else littAff.setMessage("Erreur : commande inconnue");
}
    catch(ComputerException& c){
        littAff.setMessage(c.getInfo());
    }

}

void Controleur::save(){
     qDebug()<<"save - "<<history_index;
     careTaker.add(saveEtatToMemento(littAff), history_index);
     history_index++;
     while (careTaker.taille()>history_index){
         careTaker.pop();
         qDebug()<<"pop";
     }
 }

 void Controleur::loadPrecedent(){
     if (history_index>1){
         history_index--;
         qDebug()<<"charger - "<<history_index-1;
         getEtatFromMemento(careTaker.get(history_index-1));
     }
 }

 void Controleur::loadSuivant(){
     if (history_index<careTaker.taille()){
         history_index++;
        qDebug()<<"charger - "<<history_index-1;
         getEtatFromMemento(careTaker.get(history_index-1));
     }
 }
