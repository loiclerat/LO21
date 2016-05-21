#include "qcomputer.h"

QComputer::QComputer(QWidget* parent):QWidget(parent){
    message=new QLineEdit(this);
    commande= new QLineEdit(this);
    //clavier= new QVBoxLayout;//ajouter clavier à la couche


    couche=new QVBoxLayout(this);

    couche->addWidget(message);
    couche->addWidget(commande);

    setWindowTitle("UTComputer");
    message->setReadOnly(true);
    message->setStyleSheet("color: blue;"
                           "background-color: yellow;"
                           "selection-color: yellow;"
                           "selection-background-color: blue;");


    setLayout(couche);
}


void QComputer::getNextCommande(){
    //si c'est un nombre empile si operateur on applique
    QString c=commande->text();
    //controleur->commande(c);
    commande->clear();
}
