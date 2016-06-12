#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <QString>
#include <QTextStream>
#include <QObject>
#include <QDebug>
#include <QMap>
#include <QList>
#include <QRegExp>
#include <QStringList>
#include "exceptions.h"
#include "litterale.h"
#include "operateurmanager.h"
#include "memento.h"
#include "operande.h"

/**
  \class Controleur
  \brief La classe articulant l'application, g�re le lien entre les objets et la calculatrice (Singleton)
 */

class Controleur {
    //! \brief Instance de controleur
    static Controleur* cinstance;
    //! \brief R�f�rence vers la pile
    Pile& littAff;
    //! \brief R�f�rence vers l'perateur manager
    operateurManager& opeMng;
    //! \brief CareTaker pour le memento
    CareTaker careTaker;
    //! \brief Entier d'indexation de l'historique
    unsigned int history_index;
    //! \brief Map d'Atome que comprend l'application
    // QMAP littAtome :
    QMap<QString, Operande*> mapAtome;


    //! \brief Constructeur en priv� de la classe Controleur - initialise les atomes et cr�ation de l'historique
    //! \param[in] o - Operateur manager&

    Controleur(operateurManager& o, Pile& v):littAff(v), opeMng(o), careTaker(), history_index(0){
        QRegExp rx("^[A-Z]([A-Z]|[0-9])*");
        for(operateurManager::iterator it=opeMng.begin(); it!=opeMng.end(); ++it){
            if (rx.exactMatch((*it).getSymbol())) mapAtome.insert((*it).getSymbol(), &(*it));
        }
        save();
    }
    //! \brief Constructeur de recopie de la classe Controleur en priv� (Singleton)
    Controleur(Controleur& c):littAff(c.littAff), opeMng(c.opeMng), careTaker(), history_index(0) {}
    //! \brief Destructeur de la classe Controleur en priv� (Singleton)
    ~Controleur() {}

public:

    //=========================================================//
    //===============Gestion de l'instance=================//
    //=========================================================//
    //! \brief Rcup�rer l'instance unique de Controleur
    //! \param pile de type Pile
    //! \return \e Controleur&, l'attribut static d'instance de controleur
    static Controleur& getInstance(Pile *pile = 0);

    //! \brief Lib�ration de l'instance
    static void libererInstance();

    //! \brief M�thode getterPile afin de r�cup�rer l'attribut de Pile pour pouvoir la manipuler
    //! \return \e Pile&, pointeur vers la pile
    Pile& getterPile(){
        return littAff;
    }


    //=========================================================//
    //===============Gestion de l'application=================//
    //=========================================================//
    //! \brief M�thode commande de Controleur
    //! \param c de type const QString&
    void commande(const QString& c);


    //=========================================================//
    //===============D�termination de la ligne de commande=================//
    //=========================================================//
    //! \brief M�thode estOperateur afin de savoir si la QString pass�e en param�tre est un operateur
    //! \param s de type const QString
    //! \return \e operateur* qui pointe l'operateur en question
    operateur* estOperateur(const QString s);

    //! \brief Retourne une chaine de caract�re correspondant au type de litt�rale que le manager de litt�rales devra cr�er ou une chaine de caract�re nulle s'il ne reconnaît pas la suite de symboles entr�s
    //! \brief Test pour voir s'il s'agit d'une littEntiere
    //! \brief Test pour voir s'il s'agit d'une littReelle
    //! \param s de type const QString
    //! \return \e QString contenant le type de la litterale
    QString estLitterale(const QString s);

    //! \brief M�thode estLitteraleAtome afin de savoir si la QString pass�e en param�tre est un atome
    //! \param s de type const QString
    //! \return \e Operande* qui pointe vers l'operande en question
    Operande *estLitteraleAtome(const QString s);


    //=========================================================//
    //===============Fabrique et cr�ation d'op�rande=================//
    //=========================================================//

    //! \brief M�thode FactoryMethod qui cr�e une liste d'op�rande afin de les �valuer dans la m�thode commande()
    //! \param str de type const QString
    //! \return \e QList d'Operande*, pour les traiter dans la calculatrice
    QList<Operande*> FactoryMethod(QString str);

    //! \brief M�thode CreateConcrete qui cr�e l'op�rande en d�duisant son type de la QString pass� en param�tre
    //! \param str de type const QString
    //! \return \e Operande*, pointeur vers l'op�rande cr�e
    Operande* CreateConcrete(QString str);

    //=========================================================//
    //===============Memento=================//
    //=========================================================//

    //! \brief M�thode saveEtatToMemento qui cr�e l'�tat du memento
    //! \param p de type const Pile&
    //! \return \e Memento&, r�f�rence vers l'objet Memento cr�e
    Memento& saveEtatToMemento(Pile& p){ return *(new Memento(p));}

    //! \brief M�thode getEtatFromMemento qui transmet l'�tat de la pile au memento
    //! \param m de type const Memento
    void getEtatFromMemento(Memento& m){ littAff = m.getEtat(); }

    //! \brief M�thode save qui sauvegarde l'�tat de la pile
    void save();

    //! \brief M�thode loadPrecedent qui permet de revenir �  l'�tat pr�c�dent de la pile
    void loadPrecedent();

    //! \brief M�thode loadSuivant qui permet de revenir �  l'�tat suivant de la pile
    void loadSuivant();

    //! \brief M�thode reload qui permet de recharger l'�tat courant de la pile
    void reload();
};

#endif // CONTROLEUR_H
