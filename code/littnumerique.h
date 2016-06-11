/**
\file littNumerique.h
\date 03/06/2016
\author LoÃ¯c Lerat, AndrÃ©a Vibert, ThÃ©o Hordequin
\version 1.0
\brief  Classe littcomplexe

Description de la classe littérale numérique

**/

#ifndef LITTNUMERIQUE_H
#define LITTNUMERIQUE_H
#include "littnumber.h"

/**
  \class littNumerique
  \brief La classe correspond �  toutes les littérales correspondant aux littérales numériques
 */
class littNumerique : public littnumber{

public :

    // **************************************** //
    //          Défini précédemment
    // **************************************** //
    virtual QString affichage(QString f="")const=0;//a definir
    virtual litterale* simplifier(){return this;}
    virtual bool isNull()=0;
    virtual bool isPos()=0;

    virtual littnumber* operator+(littnumber* a)=0;
    littnumber* operator-(littnumber* a);
    virtual littnumber* operator*(littnumber* a)=0;
    virtual littnumber* operator/(littnumber* a)=0;

    // **************************************** //

    //! \brief       Operator + de la litterale concernant l'addition
    //! \details    Surchage qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument).
    //! \param    a         littNumerique*
    //! \return    Un \e littNumerique* -> pointeur vers une littérale numérique qui contient la construction concrète d'un objet fille.
    //!
    virtual littNumerique* operator+(littNumerique* a)=0;

    //! \brief       Operator - de la litterale concernant la soustraction
    //! \details    Surchage qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument).
    //! \param    a         littNumerique*
    //! \return    Un \e littNumerique* -> pointeur vers une littérale numérique qui contient la construction concrète d'un objet fille.
    //!
    virtual littNumerique* operator-(littNumerique* a)=0;
    //! \brief       Operator * de la litterale concernant la multiplication
    //! \details    Surchage qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument).
    //! \param    a         littNumerique*
    //! \return    Un \e littNumerique* -> pointeur vers une littérale numérique qui contient la construction concrète d'un objet fille.
    //!
    virtual littNumerique* operator*(littNumerique* a)=0;

    //! \brief       Operator / de la litterale concernant la division
    //! \details    Surchage qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument).
    //! \param    a         littNumerique*
    //! \return    Un \e littNumerique* -> pointeur vers une littérale numérique qui contient la construction concrète d'un objet fille.
    //!
    virtual littNumerique* operator/(littNumerique* a)=0;
};
#endif // LITTNUMERIQUE_H
