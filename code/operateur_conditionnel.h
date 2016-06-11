/**
\file operateur_conditionnel.h
\date 03/06/2016
\author LoÃ¯c Lerat, AndrÃ©a Vibert, ThÃ©o Hordequin
\version 1.0
\brief  Classe operateur_conditionnel

Description de la classe operateur_conditionnel

**/

#ifndef OPERATEUR_CONDITIONNEL_H
#define OPERATEUR_CONDITIONNEL_H


#include "operateur.h"

/**
  \class operateur_conditionnel
  \brief La classe mère de tous les opérateurs conditionnels
 */
class operateur_conditionnel : public operateur {
public:
    //! \brief  Constructeur de l'opérateur conditionnel -> fait appel au constructeur de la classe operateur
    //! \param  f QString
    //! \param  a int
    operateur_conditionnel(int a, QString s)
        : operateur(a, s)
    {
    }

    virtual litterale& traitement(litterale& a, litterale& b) = 0;
    virtual litterale& traitement(litterale& a) = 0;
};

#endif // OPERATEUR_CONDITIONNEL_H
