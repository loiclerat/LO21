/**
\file littreelle.h
\date 03/06/2016
\author Loïc Lerat, Andréa Vibert, Théo Hordequin
\version 1.0
\brief  Classe littreelle

Description de la classe litterale réelle

**/

#ifndef LITTREELLE_H
#define LITTREELLE_H

#include "littnumerique.h"
#include "littentiere.h"
#include <math.h>

/*avec de la manipulation de char on va rיussir א obtenir le nombre (i)
*de chiffres aprטs la virgule et on pourra transformer en int puis faire i itיration du int*0.1 et stocker dans la partie entiטre
*/

/*Dans les littReelles on n'aura de signe nיgatif que dans les parties entiטres
*
*/

/**
  \class littReelle
  \brief La classe correspond aux littérales réelles
 */
class littReelle : public littNumerique {
    float valeur;
    int entiere;
    float decimale;

public:
    //! \brief Constructeur de littérale réelle ( arguments : e = entier (matisse), d = réel (décimale) )
    //! \param    e         int
    //! \param    d         float
    littReelle(int e, float d): valeur(e + d), entiere(e), decimale(d){}

    //! \brief Constructeur de littérale réelle ( arguments : d = réelle (décimale))
    //! \param    d         float
    littReelle(float d): valeur(d), entiere(0), decimale(d){} //Ex : ne prend que les .45 et le traduit directement comme un 0.45

    //pas de constructeur avec seulement e sinon on a un entier

    //! \brief Destructeur de littérale réelle
    ~littReelle() {}

    //! \brief Getter de la valeur du réelle
    //! \return    Un \e float possédant le contenue de la littérale.
    float getValeur() const { return valeur; }
    //! \brief Getter de la matisse du réelle
    //! \return    Un \e entier possédant le contenue de la matisse.
    int getEntiere() const { return entiere; }
    //! \brief Getter de la décimale du réelle
    //! \return    Un \e entier possédant le contenue de la décimale.
    float getDecimale() const { return decimale; }
    litterale* simplifier();

    bool isNull(){
        if(valeur==0.0){
            return true;
        }
        else return false;
    }

    bool isPos(){
        if(valeur>0){
            return true;
        }
        else return false;
    }

    QString affichage(QString f = "") const
    {
        f.append(QString::number(getValeur()));
        return f;
    }

    /*==========*/
    //! \brief       Operator + de la litterale concernant l'addition
    //! \details    Surchage de la classe spécifique qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument)
    //!             renvoi une littérale rationnelle
    //! \param    b         littReelle*
    //! \return    Un \e littReelle* -> pointeur vers une littérale réelle qui contient la construction concrète d'un objet fille.
    //!
    littReelle* operator+(littReelle* b);
    littNumerique* operator+(littNumerique* b);
    littnumber* operator+(littnumber* b);
    /*==========*/
    //! \brief       Operator - de la litterale concernant la soustraction
    //! \details    Surchage de la classe spécifique qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument)
    //!             renvoi une littérale rationnelle
    //! \param    b         littReelle*
    //! \return    Un \e littReelle* -> pointeur vers une littérale réelle qui contient la construction concrète d'un objet fille.
    //!
    littReelle* operator-(littReelle* b);
    littNumerique* operator-(littNumerique* b);
    littnumber* operator-(littnumber* b);
    /*==========*/
    //! \brief       Operator * de la litterale concernant la multiplication
    //! \details    Surchage de la classe spécifique qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument)
    //!             renvoi une littérale rationnelle
    //! \param    b         littReelle*
    //! \return    Un \e littReelle* -> pointeur vers une littérale réelle qui contient la construction concrète d'un objet fille.
    //!
    littReelle* operator*(littReelle* b);
    littNumerique* operator*(littNumerique* b);
    littnumber* operator*(littnumber* b);
    /*==========*/
    //! \brief       Operator / de la litterale concernant la division
    //! \details    Surchage de la classe spécifique qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument)
    //!             renvoi une littérale rationnelle
    //! \param    b         littReelle*
    //! \return    Un \e littReelle* -> pointeur vers une littérale réelle qui contient la construction concrète d'un objet fille.
    //!
    littReelle* operator/(littReelle* b);
    littNumerique* operator/(littNumerique* b);
    littnumber* operator/(littnumber* b);
    /*==========*/
};

#endif // LITTREELLE_H
