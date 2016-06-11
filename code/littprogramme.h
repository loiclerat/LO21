/**
\file littprogramme.h
\date 03/06/2016
\author LoÃ¯c Lerat, AndrÃ©a Vibert, ThÃ©o Hordequin
\version 1.0
\brief  Classe littProgramme

Description de la classe littérale programme

**/

#ifndef LITTPROGRAMME_H
#define LITTPROGRAMME_H

#include "litterale.h"

/**
  \class littProgramme
  \brief La classe des littérales programmes
 */
class littProgramme : public litterale
{
    //! \brief Attribut :
    //! str : \e QString concernant la chaine de caractère du programme
    QString str;
public:

    //! \brief Constructeur de littérale programme
    //! \param    s         QString
    littProgramme(QString s):str(s){}

    //! \brief Destructeur de littérale programme
    ~littProgramme(){}

    QString affichage(QString f="")const{
        f.append(str);
        return f;
    }

    //! \brief       Getter
    //! \return    Un \e QString possédant le contenue de la littérale.
    //!
    QString getStr(){
        return str;
    }

    bool isNull(){
        if(str == ""){
            return true;
        }else return false;
    }

};

#endif // LITTPROGRAMME_H
