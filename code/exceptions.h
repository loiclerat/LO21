/**
\file exceptions.h
\date 03/06/2016
\author LoÃ¯c Lerat, AndrÃ©a Vibert, ThÃ©o Hordequin
\version 1.0
\brief  Classe litterale

Description de la classe ComputerException

**/


#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <QString>

/**
  \class ComputerException
  \brief La classe qui gère les exceptions de l'application
 */
class ComputerException {

    //! \brief Attribut :
    //! info : \e QString concernant le message d'erreur à transmettre
    QString info;
public:

    //! \brief Constructeur de la classe ComputerException
    //! \param  str QString de l'erreur
    ComputerException(const QString& str):info(str){}


    //! \brief Getter de la classe ComputerException afin de récupérer le message d'erreur
    //! \return  \e QString de l'erreur
    QString getInfo() const { return info; }
};

#endif // EXCEPTIONS_H
