#include "parametres.h"
#include <QDebug>


Parametres::Parametres(unsigned int& c, unsigned int& s, QWidget *parent):QWidget(parent), clav(c), sons(s){

    this->setFixedSize(400, 250);
    setWindowTitle("UTComputer");

    couche = new QVBoxLayout();

    son = new QCheckBox("Son des messages d'erreur (ON/OFF)", this);
    son->setChecked(sons == 2);
    clavier = new QCheckBox("Affichage du clavier cliquable", this);
    clavier->setChecked(clav == 2);
    nbitem = new QSpinBox(this);
    nbitem->setValue(Pile::getNbItemsToAffiche());
    submit = new QPushButton("Appliquer", this);

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
    if (clavier->isChecked() == true)clav = 1;
    else clav = 0;
    if (son->isChecked() == true) sons = 1;
    else sons = 0;
    Pile::setNbItemsToAffiche(nbitem->value());
    emit ferme();
    this->close();
}

