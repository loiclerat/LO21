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

Controleur& Controleur::getInstance(Pile* pile){
    //Si l'instance n'existe pas, on crée un nouveau controleur avec l'instance d'OperateurManager et la pile
    if (cinstance==0) cinstance=new Controleur(operateurManager::getInstance(),*pile);
    //Sinon on retourne l'instance de Controleur
    return *cinstance;
}

void Controleur::libererInstance(){
    //Libère l'instance de Controleur
    delete cinstance;
    //Met �  0 l'attribut de Controleur -> permet d'en créer une nouvelle par la suite
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
    //Pointeur vers operateur si le QString est un operateur
    operateur* op;

    //Pointeur vers l'opérande si le QString est un atome
    Operande* at = estLitteraleAtome(c);

    //Si c'est un atome
    if (at) {
        //Polymorphisme -> dynamic_cast afin de savoir quel est le type concret de at
        operateur* ope = dynamic_cast<operateur*>(at);
        litterale* litt = dynamic_cast<litterale*>(at);

        if (ope)
            c = ope->getSymbol();
        else if (litt)
            c = litt->affichage();
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
    //Si le premier caractère de la QString est un [ , alors c'est un programme, on le créer puis on le retourne
    else if (c[0] == '[') {
        littProgramme* p = new littProgramme(c);
        return p;
    }
    else if ((op = estOperateur(c)) != 0) {
        return (op);
    }
    else {
        throw ComputerException("Ceci n'est pas une litterale ou un operateur");
    }
}

QList<Operande*> Controleur::FactoryMethod(QString str)
{
    QList<Operande*> list;
    QStringList prog;
    QStringList t;

    try {
        //Procédure pour savoir si c'est un programme, si il est bien écrit, présence d'autant de [ que de ]
        prog = str.split('[');
        if (prog.length() != 0) {
            unsigned int taille = prog.length();
            t = str.split(']');
            if (t.length() == taille) {
                for (unsigned int j = 0; j < taille; j++) {
                    qDebug() << (prog[j].split(']', QString::SkipEmptyParts));
                }
            }
            else {
                throw ComputerException("le prog n'est pas valide");
            }
        }

        //Regexp afin de supprimer les esapces
        QRegExp rx("(\\ )");

        //listOperande contient tous les caractères splités entre les espaces
        QStringList listOperande = str.split(rx, QString::SkipEmptyParts);

        //Entiers pour gérer les programmes
        unsigned int openCroch = 0;
        unsigned int closenCroch = 0;

        //Boucle qui parcours toute la liste d'opérande
        for (unsigned int i = 0; i < listOperande.length(); i++) {
            if (listOperande[i] == "[") {
                //On commence un programme
                openCroch++;
                QString Programme = "";
                //On l'ajoute �  la Qstring qui va être renvoyer �  Create Concrete
                Programme += listOperande[i];
                while (openCroch != closenCroch && i < listOperande.length() - 1) {
                    i++;
                    if (listOperande[i] == "[")
                        openCroch++;
                    if (listOperande[i] == "]")
                        closenCroch++;
                    // Stocke dans une liste les opérandes du programme
                    Programme += " " + listOperande[i];
                }
                //On passe la QString du progrmame �  CreateConcrete afin de créer l'objet Programme
                list.append(CreateConcrete(Programme));
            }
            //Sinon c'est une litterale ou un operateur basique
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

    //Liste d'opérande qui va être créer avec la FactoryMethode
    littAff.setMessage("");
    QList<Operande*> list;
    list = FactoryMethod(c);
    try{
        //Boucle qui va parcourir toute la liste d'opérande
        for (unsigned int i = 0; i < list.size(); ++i) {
            //Si l'opérande passée dans la liste est une litterale (Polymorphisme)
                litterale* lit = dynamic_cast<litterale*>(list[i]);
                //Si l'opérande passée dans la liste est un opérateur (Polymorphisme)
                operateur* ope = dynamic_cast<operateur*>(list[i]);
                //Si c'est une littérale, on empile
                if (lit != 0) {
                    littAff.push(*lit);
                    save();
                }
                //Sinon on regarde l'arité de l'operateur
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
                        qDebug()<<ptr;
                        if (ptr==0){ reload(); throw ComputerException("Erreur : operation impossible");}
                        littAff.push(*ptr);
                        save();
                    }
                    else
                        throw ComputerException("Erreur : pas assez d'arguments");
                }
            }

}catch (ComputerException& c){
            littAff.setMessage(c.getInfo());
    }
}

void Controleur::save()
{
    while (careTaker.taille() > history_index) {
        careTaker.pop();
        qDebug() << "pop";
    }
    qDebug() << "save - " << history_index;
    careTaker.add(saveEtatToMemento(littAff), history_index);
    history_index++;

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

void Controleur::reload()
{
    if (history_index > 1) {
        qDebug() << "charger - " << history_index - 1;
        getEtatFromMemento(careTaker.get(history_index - 1));
    }
}
