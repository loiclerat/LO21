/**
\file littnumber.h
\date 03/06/2016
\author Lo?c Lerat, Andr?a Vibert, Th?o Hordequin
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
  \brief La classe correspond ?  toutes les litt?rales correspondant aux nombres
 */
class littnumber : public litterale
{
public:
    virtual ~littnumber(){}

    virtual QString affichage(QString f="")const=0;//a definir
    virtual litterale* simplifier(){return this;}
    virtual bool isNull()=0;
    //! \brief       D?termine si la litt?rale nombre est positive.
    //! \return    Un \e bool?en : true si la litterale est nulle, faux sinon.
    //!
    virtual bool isPos()=0;

    //! \brief       Operator + de la litterale concernant l'addition
    //! \param    a         littnumber*
    //! \return    Un \e littnumber* -> pointeur vers une litt?rale number qui contient la construction concr?te d'un objet fille.
    //!
    virtual littnumber* operator+(littnumber* a)=0;
    //! \brief       Operator - de la litterale concernant la soustraction
    //! \param    a         littnumber*
    //! \return    Un \e littnumber* -> pointeur vers une litt?rale number qui contient la construction concr?te d'un objet fille.
    //!
    virtual littnumber* operator-(littnumber* a)=0;

    //! \brief       Operator + de la litterale concernant la multiplication
    //! \param    a         littnumber*
    //! \return    Un \e littnumber* -> pointeur vers une litt?rale number qui contient la construction concr?te d'un objet fille.
    //!
    virtual littnumber* operator*(littnumber* a)=0;
    //! \brief       Operator + de la litterale concernant la division
    //! \param    a         littnumber*
    //! \return    Un \e littnumber* -> pointeur vers une litt?rale number qui contient la construction concr?te d'un objet fille.
    //!
    virtual littnumber* operator/(littnumber* a)=0;


};

#endif // LITTNUMBER_H
