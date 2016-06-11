#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <QString>
#include <QTextStream>
#include <QObject>
#include <QDebug>
#include <QMap>
#include <QList>
#include <QRegExp>
#include "operateurmanager.h"
#include "memento.h"
#include "operande.h"

/**
  \class Controleur
  \brief La classe articulant l'application, gère le lien entre les objets et la calculatrice (Singleton)
 */

class Controleur {
    //! \brief Instance de controleur
    static Controleur* cinstance;
    //! \brief Référence vers la pile
    Pile& littAff;
    //! \brief Référence vers l'perateur manager
    operateurManager& opeMng;
    //! \brief CareTaker pour le memento
    CareTaker careTaker;    
    //! \brief Entier d'indexation de l'historique
    unsigned int history_index;
    //! \brief Map d'Atome que comprend l'application
    // QMAP littAtome :
    QMap<QString, Operande*> mapAtome;


    //! \brief Constructeur en privé de la classe Controleur - initialise les atomes et création de l'historique
    //! \param[in] o - Operateur manager&
    Controleur(operateurManager& o, Pile& v):littAff(v), opeMng(o), careTaker(), history_index(0){
        QRegExp rx("^[A-Z]([A-Z]|[0-9])*");
        for(operateurManager::iterator it=opeMng.begin(); it!=opeMng.end(); ++it){
            if (rx.exactMatch((*it).getSymbol())) mapAtome.insert((*it).getSymbol(), &(*it));
        }
        save();
    }
    //! \brief Constructeur de recopie de la classe Controleur en privé (Singleton)
    Controleur(Controleur& c):littAff(c.littAff), opeMng(c.opeMng), careTaker(), history_index(0) {}
    //! \brief Destructeur de la classe Controleur en privé (Singleton)
    ~Controleur() {}

public:

    //=========================================================//
    //===============Gestion de l'instance=================//
    //=========================================================//
    //! \brief Récupérer l'instance unique de Controleur
    //! \param pile de type Pile
    //! \return \e Controleur&, l'attribut static d'instance de controleur
    static Controleur& getInstance(Pile *pile = 0);

    //! \brief Libération de l'instance
    static void libererInstance();

    //! \brief Méthode getterPile afin de récupérer l'attribut de Pile pour pouvoir la manipuler
    //! \return \e Pile&, pointeur vers la pile
    Pile& getterPile(){
        return littAff;
    }


    //=========================================================//
    //===============Gestion de l'application=================//
    //=========================================================//
    //! \brief Méthode commande de Controleur
    //! \param c de type const QString&
    void commande(const QString& c);


    //=========================================================//
    //===============Détermination de la ligne de commande=================//
    //=========================================================//
    //! \brief Méthode estOperateur afin de savoir si la QString passée en paramètre est un operateur
    //! \param c de type const QString
    //! \return \e operateur* qui pointe l'operateur en question
    operateur* estOperateur(const QString s);

    //! \brief Retourne une chaine de caractère correspondant au type de littérale que le manager de littérales devra créer ou une chaine de caractère nulle s'il ne reconnaît pas la suite de symboles entrés
    //! \brief Test pour voir s'il s'agit d'une littEntiere
    //! \brief Test pour voir s'il s'agit d'une littReelle
    //! \param s de type const QString
    //! \return \e QString contenant le type de la litterale
    QString estLitterale(const QString s);

    //! \brief Méthode estLitteraleAtome afin de savoir si la QString passée en paramètre est un atome
    //! \param s de type const QString
    //! \return \e Operande* qui pointe vers l'operande en question
    Operande *estLitteraleAtome(const QString s);


    //=========================================================//
    //===============Fabrique et création d'opérande=================//
    //=========================================================//

    //! \brief Méthode FactoryMethod qui crée une liste d'opérande afin de les évaluer dans la méthode commande()
    //! \param str de type const QString
    //! \return \e QList d'Operande*, pour les traiter dans la calculatrice
    QList<Operande*> FactoryMethod(QString str);

    //! \brief Méthode CreateConcrete qui crée l'opérande en déduisant son type de la QString passé en paramètre
    //! \param str de type const QString
    //! \return \e Operande*, pointeur vers l'opérande crée
    Operande* CreateConcrete(QString str);

    //=========================================================//
    //===============Memento=================//
    //=========================================================//

    //! \brief Méthode saveEtatToMemento qui crée l'état du memento
    //! \param p de type const Pile&
    //! \return \e Memento&, référence vers l'objet Memento crée
    Memento& saveEtatToMemento(Pile& p){ return *(new Memento(p));}

    //! \brief Méthode getEtatFromMemento qui transmet l'état de la pile au memento
    //! \param m de type const Memento
    void getEtatFromMemento(Memento& m){ littAff = m.getEtat(); }

    //! \brief Méthode save qui sauvegarde l'état de la pile
    void save();

    //! \brief Méthode loadPrecedent qui permet de revenir �  l'état précédent de la pile
    void loadPrecedent();

    //! \brief Méthode loadSuivant qui permet de revenir �  l'état suivant de la pile
    void loadSuivant();

    //! \brief Méthode reload qui permet de recharger �  l'état de la pile
    void reload();
};

#endif // CONTROLEUR_H
