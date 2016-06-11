#include "parametres.h"


Parametres::Parametres(QWidget *parent):QWidget(parent){



    this->setFixedSize(400, 250);
    setWindowTitle("UTComputer");

    couche = new QVBoxLayout();

    son = new QCheckBox("Son des messages d'erreur (ON/OFF)", this);
    clavier = new QCheckBox("Affichage du clavier cliquable", this);
    nbitem = new QSpinBox(this);
    submit = new QPushButton("Appliquer", this);

    nbitem->setMaximum(10);
    nbitem->setMinimum(2);

    couche->addWidget(son);
    couche->addWidget(clavier);
    couche->addWidget(nbitem);
    couche->addWidget(submit);;
    setLayout(couche);

    connect(submit, SIGNAL(pressed()), this, SLOT(submitPressed()));
}


void Parametres::submitPressed(){
    this->close();
}
