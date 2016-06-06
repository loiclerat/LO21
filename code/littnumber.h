/**
\file littnumber.h
\date 03/06/2016
\author Loïc Lerat, Andréa Vibert, Théo Hordequin
\version 1.0
\brief  Classe littnumber

Description de la classe litterale nombre

**/


#ifndef LITTNUMBER_H
#define LITTNUMBER_H
#include "litterale.h"

using namespace std;
/**
  \class littnumber
  \brief La classe correspond à toutes les littérales correspondant aux nombres
 */
class littnumber : public litterale
{
public:
    //! \brief       Constructeur de la litterale number
    //!
    littnumber(){}
    //! \brief       Destructeur de la litterale number
    //!
    virtual ~littnumber(){}

    virtual QString affichage(QString f="")const=0;//a definir
    virtual void simplifier(){}
    virtual bool isNull()=0;
    //! \brief       Détermine si la littérale nombre est positive.
    //! \return    Un \e booléen : true si la litterale est nulle, faux sinon.
    //!
    virtual bool isPos()=0;

    //! \brief       Operator + de la litterale concernant l'addition
    //! \param    a         littnumber*
    //! \return    Un \e littnumber* -> pointeur vers une littérale number qui contient la construction concrète d'un objet fille.
    //!
    virtual littnumber* operator+(littnumber* a)=0;
    //! \brief       Operator - de la litterale concernant la soustraction
    //! \param    a         littnumber*
    //! \return    Un \e littnumber* -> pointeur vers une littérale number qui contient la construction concrète d'un objet fille.
    //!
    virtual littnumber* operator-(littnumber* a)=0;

    //! \brief       Operator + de la litterale concernant la multiplication
    //! \param    a         littnumber*
    //! \return    Un \e littnumber* -> pointeur vers une littérale number qui contient la construction concrète d'un objet fille.
    //!
    virtual littnumber* operator*(littnumber* a)=0;
    //! \brief       Operator + de la litterale concernant la division
    //! \param    a         littnumber*
    //! \return    Un \e littnumber* -> pointeur vers une littérale number qui contient la construction concrète d'un objet fille.
    //!
    virtual littnumber* operator/(littnumber* a)=0;


};

#endif // LITTNUMBER_H
