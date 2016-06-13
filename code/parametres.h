/**
\file parametres.h
\date 03/06/2016
\author Loïc Lerat, Andréa Vibert, Théo Hordequin
\version 1.0
\brief  Fenêtre de gestion des paramètres

Description de la classe Paramètres ainsi que ses slots et signaux

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
    //! \brief Nombre d'items de la Pile à afficher
    QSpinBox* nbitem;
    //! \brief Application des changements et fermeture de la fenêtre
    QPushButton* submit;
    QVBoxLayout* couche;
    QLabel* label;

    //! \brief Référence vers la variable d'état d'affichage du clavier de QComputer
    unsigned int& clav;
    //! \brief Référence vers la variable d'état d'activation des sons de QComputer
    unsigned int& sons;

public:

    //! \brief Constructeur
    explicit Parametres(unsigned int& c, unsigned int& s, QWidget *parent = 0);

public slots:

    //! \brief Application des changements et fermeture de la fenêtre
    void submitPressed();

signals:

    //! \brief Signal envoyé à QComputer lors de la fermeture
    void ferme();

};

#endif // PARAMETRES_H
