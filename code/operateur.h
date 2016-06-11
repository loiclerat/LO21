/**
\file operateur.h
\date 03/06/2016
\author LoÃ¯c Lerat, AndrÃ©a Vibert, ThÃ©o Hordequin
\version 1.0
\brief  Classe operateur

Description de la classe Operateur

**/

#ifndef OPERATEUR_H
#define OPERATEUR_H
#include "litterale.h"

/**
  \class operateur
  \brief La classe est la classe mère de tous les types d'operateurs
 */
class operateur : public Operande {
protected:
    //! \brief Attribut :
    //! arite : \e int concernant l'arité de l'opérateur
    int arite;

    //! \brief Attribut :
    //! symbol : \e QString concernant le nom de l'opérateur
    QString symbol;

public:
    //! \brief  Constructeur de l'opérateur
    //! \param  f QString
    //! \param  a int
    operateur(int a, QString s)
        : arite(a)
        , symbol(s)
    {
    }

    //! \brief  Getter de l'arité de l'opérateur
    //! \return  int correspondant à l'arité de l'opérateur
    int getArite() { return arite; }

    //! \brief  Getter du symbol de l'opérateur
    //! \return  QString correspondant au nom de l'opérateur
    QString getSymbol() { return symbol; }

    //! \brief  Traitement de l'opérateur, méthode qui exécute le fonctionnement de l'opérateur || Cas arité 2. Elle est redéfini dans toutes les classes filles
    //! \param a litterale& -> première littérale en argument
    //! \param b litterale& -> seconde littérale en argument
    //! \return  un \e litterale& correspondant à une référence vers une litterale crée par le traitement
    virtual litterale& traitement(litterale& a, litterale& b) = 0;

    //! \brief  Traitement de l'opérateur, méthode qui exécute le fonctionnement de l'opérateur || Cas arité 1. Elle est redéfini dans toutes les classes filles
    //! \param a litterale& -> littérale en argument
    //! \return  un \e litterale& correspondant à une référence vers une litterale crée par le traitement
    virtual litterale& traitement(litterale& a) = 0;


    //! \brief  Traitement de l'opérateur, méthode qui exécute le fonctionnement de l'opérateur || Cas arité 0. Elle est redéfini dans toutes les classes filles
    //!
    virtual void traitement() = 0;

};

#endif // OPERATEUR_H
