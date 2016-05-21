#ifndef QCOMPUTER_H
#define QCOMPUTER_H
    #include <QWidget>
    #include <QLineEdit>
    #include <QTextEdit>
    #include <QTableWidget>
    #include <QVBoxLayout>
    #include <QHeaderView>
    #include <QDebug>

    class QComputer : public QWidget{
        Q_OBJECT
        QLineEdit* message;
        QLineEdit* commande;
        QVBoxLayout* couche;

    public :
        explicit QComputer(QWidget *parent = 0);
        void getNextCommande();
    };

#endif // QCOMPUTER_H
