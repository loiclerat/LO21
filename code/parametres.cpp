/**
\file parametres.cpp
\date 03/06/2016
\author Loïc Lerat, Andréa Vibert, Théo Hordequin
\version 1.0
\brief  Fenêtre d'édition des paramètres de QComputer


Définition des méthodes de la classe Parametres
**/

#include "parametres.h"


Parametres::Parametres(unsigned int& c, unsigned int& s, QWidget *parent):QWidget(parent), clav(c), sons(s){


    this->setFixedSize(400, 250);
    setWindowTitle("UTComputer");

    // Layout principal

    couche = new QVBoxLayout();

    // Paramètres modifiables initialisés en fonction de l'état de QComputer
    // transmit via les références clav et sons

    son = new QCheckBox("Son des messages d'erreur (ON/OFF)", this);
    son->setChecked(sons == 2);
    clavier = new QCheckBox("Affichage du clavier cliquable", this);
    clavier->setChecked(clav == 2);
    nbitem = new QSpinBox(this);
    nbitem->setValue(Pile::getNbItemsToAffiche());
    submit = new QPushButton("Appliquer", this);


    // Disposition graphique

    nbitem->setMaximum(10);
    nbitem->setMinimum(2);
    label = new QLabel("Nombre d'éléments de la pile à afficher : ", this);
    label->setFixedSize(400, 20);
    couche->addWidget(son);
    couche->addWidget(clavier);
    couche->addWidget(label);
    couche->addWidget(nbitem);
    couche->addWidget(submit);;
    setLayout(couche);

    connect(submit, SIGNAL(pressed()), this, SLOT(submitPressed()));
}


void Parametres::submitPressed(){
    if (clavier->isChecked() == true)clav = 1;  // 1 signifie "en cours d'affichage"
    else clav = 0;                              // 0 signifie "en cours de masquage"
    if (son->isChecked() == true) sons = 1;     // 1 signifie "en cours d'activation"
    else sons = 0;                              // 0 signifie "en cours de desactivation"
    Pile::setNbItemsToAffiche(nbitem->value()); // Nombre d'éléments de la PIle à afficher
    emit ferme();
    this->close();
}

