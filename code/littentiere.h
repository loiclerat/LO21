/**
\file littentiere.h
\date 03/06/2016
\author Loïc Lerat, Andréa Vibert, Théo Hordequin
\version 1.0
\brief  Classe littentiere

Description de la classe litterale entière

**/

#ifndef LITTENTIERE_H
#define LITTENTIERE_H

#include "littrat.h"
#include "littnumerique.h"
#include "littreelle.h"
#include "littcomplexe.h"

/**
  \class littEntiere
  \brief La classe concernant les littérales entières
 */

class littEntiere : public littNumerique {
    int valeur; /*!< Entier correspondant �  la valeur  */

public:
    //! \brief Constructeur de littérale entière
    //! \param    val         int
    littEntiere(int val)
        : valeur(val)
    {
    }
    //! \brief Destructeur de littérale entière
    ~littEntiere() {}
    //! \brief       Getter
    //! \return    Un \e entier possédant le contenue de la littérale.
    //!
    int getValeur() const { return valeur; }

    bool isNull(){
        if(valeur==0){
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
    //littEntiere& operator+(littEntiere& b);

    littNumerique* operator+(littNumerique* a);
    littnumber* operator+(littnumber* a);
    /*==========*/
    //littEntiere& operator-(littEntiere& b);
    littNumerique* operator-(littNumerique* a);
    littnumber* operator-(littnumber* a);
    /*==========*/
    //littEntiere& operator*(littEntiere& b);
    littNumerique* operator*(littNumerique* a);
    littnumber* operator*(littnumber* a);
    /*==========*/
    //! \brief       Operator / de la litterale concernant la division entière
    //! \details    Surchage qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument)
    //!             renvoi un littérale numérique qui correspond �  un rationnel
    //! \param    a         littEntiere*
    //! \return    Un \e littNumerique* -> pointeur vers une littérale numérique qui contient la construction concrète d'un objet fille.
    //!
    littNumerique* operator/(littEntiere* b);
    littNumerique* operator/(littNumerique* a);
    littnumber* operator/(littnumber* a);
    /*==========*/
};

#endif //LITTENTIERE_H
