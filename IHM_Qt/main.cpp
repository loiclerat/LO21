
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

};



