#ifndef QCOMPUTER_H
#define QCOMPUTER_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QDebug>
#include <QPushButton>

class QComputer : public QWidget{
    Q_OBJECT
    QVBoxLayout* boxcomplete;
    QLineEdit* message;
    QLineEdit* commande;
    QVBoxLayout* couchehaut;
    QTableWidget* vuepile;

    QHBoxLayout* couchebas;
    QVBoxLayout* opbasique;
    QPushButton* plus;
    QPushButton* moins;
    QPushButton* mul;
    QPushButton* div;
    QPushButton* entree;


    QVBoxLayout* opnum;
    QPushButton* divB;
    QPushButton* neg;
    QPushButton* den;
    QPushButton* num;
    QPushButton* ccomplex;
    QPushButton* re;
    QPushButton* im;


    QVBoxLayout* oplog;
    QPushButton* andb;
    QPushButton* orb;
    QPushButton* notb;
    QPushButton* egal;
    QPushButton* diff;
    QPushButton* sup;
    QPushButton* inf;
    QPushButton* supeg;
    QPushButton* infeg;


    QVBoxLayout* opcond;
    QPushButton* ift;


    QVBoxLayout* oppile;
    QPushButton* dup;
    QPushButton* drop;
    QPushButton* swap;
    QPushButton* lastop;
    QPushButton* lastarg;
    QPushButton* undo;
    QPushButton* redo;
    QPushButton* clear;


public :
    explicit QComputer(QWidget *parent = 0);
    void getNextCommande();
};

#endif // QCOMPUTER_H


