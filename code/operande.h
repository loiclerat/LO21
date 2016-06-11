/**
\file operande.h
\date 03/06/2016
\author LoÃ¯c Lerat, AndrÃ©a Vibert, ThÃ©o Hordequin
\version 1.0
\brief  Classe Operande

Description de la classe Operande

**/

#ifndef OPERANDE_H
#define OPERANDE_H

/**
  \class Operande
  \brief La classe est la classe mère de toutes les littérales et opérateurs
 */
class Operande {
public:

    //! \brief  Constructeur de l'operande
    Operande(){}

    //! \brief  Destructeur de l'operande
    virtual ~Operande(){}
};


#endif // OPERANDE_H
