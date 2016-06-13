/**
\file main.cpp
\date 03/06/2016
\author Loïc Lerat, Andréa Vibert, Théo Hordequin
\version 1.0

Point d'entrée de l'application

**/


#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>

#include "qcomputer.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    QComputer fenetre;
    fenetre.show();
    return app.exec();

}
