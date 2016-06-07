/**
\file litterale.h
\date 03/06/2016
\author LoÃ¯c Lerat, AndrÃ©a Vibert, ThÃ©o Hordequin
\version 1.0
\brief  Classe litterale

Description de la classe Litterale

**/


#ifndef LITTERALE_H
#define LITTERALE_H


#include <QString>
#include <QTextStream>
#include <QObject>
#include <QDebug>

#include "exceptions.h"
#include <typeinfo>
#include <iostream>
#include <string>


using namespace std;

/**
  \class litterale
  \brief La classe est la classe mère de tous les types de littérales
 */
class litterale{
public :
    //! \brief Constructeur
    litterale(){}
    //! \brief Destructeur
    virtual ~litterale(){}

    //! \brief       Affichage de la litterale
    //! \param    f         QString
    //! \return    Un \e QString possédant tout l'affichage de la litterale.
    //!
    virtual QString affichage(QString f="")const=0;//a definir
    //! \brief       Simplificaiton de la litterale
    //!
    virtual litterale* simplifier(){return this;}/*permet de simplifier les litt num
    *d�s leur cr�ation, �ventuellement les transformer en une autre litt num
    *si possible.
    */
    //! \brief       Détermine si la litterale est nulle ou non.
    //! \return    Un \e booléen : true si la litterale est nulle, faux sinon.
    //!
    virtual bool isNull()=0;

};

#endif // LITTERALE_H
