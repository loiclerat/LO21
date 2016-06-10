/**
\file item.cpp
\date 03/06/2016
\author LoÃƒÂ¯c Lerat, AndrÃƒÂ©a Vibert, ThÃƒÂ©o Hordequin
\version 1.0
\brief  DÃ©finition des mÃ©thodes de la classe Controleur


**/

#include "controleur.h"
#include "exceptions.h"
#include "littprogramme.h"
#include <QStringList>

Controleur* Controleur::cinstance = 0;


Controleur::Controleur(operateurManager& o, Pile& v):littAff(v), opeMng(o), careTaker(), history_index(0){
    QRegExp rx("^[A-Z]([A-Z]|[0-9])*");
    for(operateurManager::iterator it=opeMng.begin(); it!=opeMng.end(); ++it){
        if (rx.exactMatch((*it).getSymbol())) mapAtome.insert((*it).getSymbol(), &(*it));
    }
    save();
}

//! \brief Récupérer l'instance unique d'operateurManager
Controleur& Controleur::getInstance(Pile* pile){
    if (cinstance==0) cinstance=new Controleur(operateurManager::getInstance(),*pile);
    return *cinstance;
}

//! \brief Libération de l'instance
void Controleur::libererInstance(){
    delete cinstance;
    cinstance=0;
}

operateur* Controleur::estOperateur(const QString s)
{
    for(operateurManager::const_iterator it=opeMng.begin_const(); it!=opeMng.end_const(); ++it){
        if ((*it).getSymbol() == s)   return &(*it);
    }
    return 0;
}

Operande* Controleur::estLitteraleAtome(const QString s){
    QRegExp rx("^[A-Z]([A-Z]|[0-9])*");
    if(rx.exactMatch(s)){//si on colle exactement avec le format Capitale puis suite de capitale et/ou chiffres alors on le cherche
        Operande* resRecherche= mapAtome.value(s,0);
        if(resRecherche) return mapAtome[s];
    }
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

Operande* Controleur::CreateConcrete(QString c)
{


    operateur* op;

try{
        Operande* at=estLitteraleAtome(c);
        if(at){
            operateur* ope = dynamic_cast<operateur*>(at);
            litterale* litt = dynamic_cast<litterale*>(at);

            if(ope) c=ope->getSymbol();
            else if (litt) c=litt->affichage();
        }
        if (estLitterale(c) != "") {
            if (estLitterale(c) == "entiere") {
                littEntiere* l = new littEntiere(c.toInt());
                return (l);
            }
            else {
                if (estLitterale(c) == "reelle") {
                    QStringList list = c.split(".");
                    QString ent = list[0];
                    QString dec = list[1];
                    if (dec == "") {
                        littEntiere* l = new littEntiere(ent.toInt());
                        return (l);
                    }
                    else {
                        littReelle* l = new littReelle(ent.toInt(), c.toFloat() - ent.toInt());
                        return (l);
                    }
                }
            }
        }
        else if (c[0] == '[') {
            littProgramme* p = new littProgramme(c);
            return p;
        }
        else if ((op = estOperateur(c)) != 0) {
            return (op);
        }
        else {
            littAff.setMessage("Erreur : commande inconnue");
            throw ComputerException("Ceci n'est pas une littérale ou un opérateur");
        }
    }
    catch (ComputerException& e) {
        littAff.setMessage(e.getInfo());
    }
}

QList<Operande*> Controleur::FactoryMethod(QString str)
{
    QList<Operande*> list;
    QStringList prog;
    QStringList t;
    QString finalp;
    bool ok;
    try {
        prog = str.split('[');
        if (prog.length() != 0) {
            int taille = prog.length();
            t = str.split(']');
            if (t.length() == taille) {
                for (int j = 0; j < taille; j++) {
                    qDebug() << (prog[j].split(']', QString::SkipEmptyParts));
                }
            }
            else {
                throw ComputerException("le prog n'est pas valide");
            }
        }

        QRegExp rx("(\\ )");

        QStringList listOperande = str.split(rx, QString::SkipEmptyParts);
        qDebug() << listOperande;
        int openPar = 0;
        int closenPar = 0;
        for (int i = 0; i < listOperande.length(); i++) {
            //int i = 0;
            if (listOperande[i] == "[") {
                openPar++;
                QString Programme = "";
                Programme += listOperande[i];
                while (openPar != closenPar && i < listOperande.length() - 1) {
                    i++;
                    if (listOperande[i] == "[")
                        openPar++;
                    if (listOperande[i] == "]")
                        closenPar++;
                    // Stocker dans une liste les opérandes du programme
                    Programme += " " + listOperande[i];
                }
                qDebug() << Programme;
                list.append(CreateConcrete(Programme));
            }
            else {
                try {
                    list.append(CreateConcrete(listOperande[i]));
                }
                catch (ComputerException& e) {
                    littAff.setMessage(e.getInfo());
                }
            }
        }
        return list;
    }
    catch (ComputerException& e) {
        littAff.setMessage(e.getInfo());
    }
}

void Controleur::commande(const QString& c)
{

    QList<Operande*> list;
    list = FactoryMethod(c);
    try{
    for (int i = 0; i < list.size(); ++i) {
        litterale* lit = dynamic_cast<litterale*>(list[i]);
        operateur* ope = dynamic_cast<operateur*>(list[i]);
        if (lit != 0) {
            littAff.push(*lit);
            save();
        }
        else if (ope->getArite() == 1) {
            if (littAff.taille() >= 1) {
                litterale& v = littAff.top();
                litterale* ptr=&(*(ope->traitement(v).simplifier()));
                if (ptr!=0){
                    littAff.pop();
                    littAff.push(*ptr);
                }
                save();
            }
            else
                throw ComputerException("Erreur : pas assez d'arguments");
        }
        else if (ope->getArite() == 2) {
            if (littAff.taille() >= 2) {
                litterale& v1 = littAff.top();
                littAff.pop();
                litterale& v2 = littAff.top();
                littAff.pop();
                litterale* ptr=&(*(ope->traitement(v2, v1).simplifier()));
                littAff.push(*ptr);
                save();
                if (ptr==0) loadPrecedent();
            }
            else
                throw ComputerException("Erreur : pas assez d'arguments");
        }
    }
}catch (ComputerException& c){
            littAff.setMessage(c.getInfo());
    }
    // analyse c -> litterale ou operateur
    // si litterale : quel type ? -> addLitterale
    // si operateur : lequel ? (iterateur pour trouver l'operateur correspondant au symbol c -> traitement()
    // setMessage...

    // Gestion de la pile dans le controlleur

    // DÃ©pilement selon aritÃ©
    // appel de traitement avec les valeurs
    // crÃ©ation d'une litterale dans traitement puis retour de ref
    // empilement de la ref
}

void Controleur::save()
{
    qDebug() << "save - " << history_index;
    careTaker.add(saveEtatToMemento(littAff), history_index);
    history_index++;
    while (careTaker.taille() > history_index) {
        careTaker.pop();
        qDebug() << "pop";
    }
}

void Controleur::loadPrecedent()
{
    if (history_index > 1) {
        history_index--;
        qDebug() << "charger - " << history_index - 1;
        getEtatFromMemento(careTaker.get(history_index - 1));
    }
}

void Controleur::loadSuivant()
{
    if (history_index < careTaker.taille()) {
        history_index++;
        qDebug() << "charger - " << history_index - 1;
        getEtatFromMemento(careTaker.get(history_index - 1));
    }
}
