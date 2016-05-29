#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include"qcomputer.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QComputer fenetre;


    fenetre.show();
    return app.exec();

}
