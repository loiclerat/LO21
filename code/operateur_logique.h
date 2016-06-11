/**
\file operateur_logique.h
\date 03/06/2016
\author LoÃ¯c Lerat, AndrÃ©a Vibert, ThÃ©o Hordequin
\version 1.0
\brief  Classe operateur_logique

Description de la classe operateur_logique

**/

#ifndef OPERATEUR_LOGIQUE_H
#define OPERATEUR_LOGIQUE_H

#include "operateur.h"

/**
  \class operateur_logique
  \brief La classe mère de tous les opérateurs logiques
 */
class operateur_logique : public operateur {
public:
    //! \brief  Constructeur de l'opérateur logique -> fait appel au constructeur de la classe operateur
    //! \param  f QString
    //! \param  a int
    operateur_logique(int a, QString s)
        : operateur(a, s)
    {
    }

    virtual litterale& traitement(litterale& a, litterale& b) = 0;
    virtual litterale& traitement(litterale& a) = 0;
    virtual void traitement() = 0;
};

#endif // OPERATEUR_LOGIQUE_H
