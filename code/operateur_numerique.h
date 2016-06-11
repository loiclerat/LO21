/**
\file operateur_numerique.h
\date 03/06/2016
\author LoÃ¯c Lerat, AndrÃ©a Vibert, ThÃ©o Hordequin
\version 1.0
\brief  Classe operateur_numerique

Description de la classe operateur_numerique

**/

#ifndef OPERATEUR_NUMERIQUE_H
#define OPERATEUR_NUMERIQUE_H
#include "operateur.h"

/**
  \class operateur_numerique
  \brief La classe mère de tous les opérateurs numerique
 */
class operateur_numerique : public operateur {
public:
    //! \brief  Constructeur de l'opérateur numerique -> fait appel au constructeur de la classe operateur
    //! \param  f QString
    //! \param  a int
    operateur_numerique(int a, QString s)
        : operateur(a, s)
    {
    }

    virtual litterale& traitement(litterale& a, litterale& b) = 0;
    virtual litterale& traitement(litterale& a) = 0;
};

#endif // OPERATEUR_NUMERIQUE_H
