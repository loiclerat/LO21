
/**
\file littrat.h
\date 03/06/2016
\author Loïc Lerat, Andréa Vibert, Théo Hordequin
\version 1.0
\brief  Classe littrat

Description de la classe litterale rationnelle

**/

#ifndef LITTRAT_H
#define LITTRAT_H

#include "littnumerique.h"
#include "littentiere.h"

/**
  \class littrat
  \brief La classe des littérales rationnelles
 */
class littrat : public littNumerique {
    int num;
    int den;

public:
    //! \brief Constructeur de littérale rationnelle (arguments : n = numérateur, d = dénominateur
    //! \param    n         int
    //! \param    d         int
    littrat(int n = 0, int d = 1)
    {
        num = n;
        den = d;
    }
    //! \brief Destructeur de littérale rationnelle
    ~littrat() {}
    litterale* simplifier();

    //! \brief Getter du numérateur
    //! \return    Un \e entier possédant le contenue du numérateur.
    int getNum() const { return num; }
    //! \brief Getter du dénominateur
    //! \return    Un \e entier possédant le contenue du dénominateur.
    int getDen() const { return den; }
    //! \brief Getter de la valeur réelle
    //! \return    Un \e float possédant le contenue du rationnelle.
    float getValeur() const { return num / den; }

    bool isNull()
    {
        if (num == 0) {
            return true;
        }
        else
            return false;
    }

    bool isPos()
    {
        if (num > 0) {
            return true;
        }
        else
            return false;
    }

    QString affichage(QString f = "") const
    {
        f.append(QString::number(getNum()));
        f.append("/");
        f.append(QString::number(getDen()));
        return f;
    }

    /*==========*/
    //! \brief       Operator + de la litterale concernant l'addition
    //! \details    Surchage qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument)
    //!             renvoi une littérale rationnelle
    //! \param    b         littrat*
    //! \return    Un \e littrat* -> pointeur vers une littérale rationnelle qui contient la construction concrète d'un objet fille.
    //!
    littrat* operator+(littrat* b);
    littNumerique* operator+(littNumerique* a);
    littnumber* operator+(littnumber* a);
    /*==========*/
    //! \brief       Operator - de la litterale concernant la soustraction
    //! \details    Surchage de la classe qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument)
    //!             renvoi une littérale rationnelle
    //! \param    b         littrat*
    //! \return    Un \e littrat* -> pointeur vers une littérale rationnelle qui contient la construction concrète d'un objet fille.
    //!
    littrat* operator-(littrat* b);
    littNumerique* operator-(littNumerique* a);
    littnumber* operator-(littnumber* a);
    /*==========*/
    //! \brief       Operator * de la litterale concernant la multiplication
    //! \details    Surchage de la classe qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument)
    //!             renvoi une littérale rationnelle
    //! \param    b         littrat*
    //! \return    Un \e littrat* -> pointeur vers une littérale rationnelle qui contient la construction concrète d'un objet fille.
    //!
    littrat* operator*(littrat* b);
    littNumerique* operator*(littNumerique* a);
    littnumber* operator*(littnumber* a);
    /*==========*/
    //! \brief       Operator / de la litterale concernant la division
    //! \details    Surchage de la classe qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument)
    //!             renvoi une littérale rationnelle
    //! \param    b         littrat*
    //! \return    Un \e littrat* -> pointeur vers une littérale rationnelle qui contient la construction concrète d'un objet fille.
    //!
    littrat* operator/(littrat* b);
    littNumerique* operator/(littNumerique* a);
    littnumber* operator/(littnumber* a);
    /*==========*/
};

#endif // LITTRAT_H
