/**
\file parametres.h
\date 03/06/2016
\author Lo�c Lerat, Andr�a Vibert, Th�o Hordequin
\version 1.0
\brief  Fen�tre de gestion des param�tres

Description de la classe Param�tres ainsi que ses slots et signaux

**/


#ifndef PARAMETRES_H
#define PARAMETRES_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QCheckBox>
#include <QSpinBox>
#include <QLabel>
#include "pile.h"

class Parametres : public QWidget{
    Q_OBJECT

    //! \brief Activation des sons
    QCheckBox* son;
    //! \brief Affichage du clavier
    QCheckBox* clavier;
    //! \brief Nombre d'items de la Pile � afficher
    QSpinBox* nbitem;
    //! \brief Application des changements et fermeture de la fen�tre
    QPushButton* submit;
    QVBoxLayout* couche;
    QLabel* label;

    //! \brief R�f�rence vers la variable d'�tat d'affichage du clavier de QComputer
    unsigned int& clav;
    //! \brief R�f�rence vers la variable d'�tat d'activation des sons de QComputer
    unsigned int& sons;

public:

    //! \brief Constructeur
    explicit Parametres(unsigned int& c, unsigned int& s, QWidget *parent = 0);

public slots:

    //! \brief Application des changements et fermeture de la fen�tre
    void submitPressed();

signals:

    //! \brief Signal envoy� � QComputer lors de la fermeture
    void ferme();

};

#endif // PARAMETRES_H
