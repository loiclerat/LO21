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
#include <QSound>
#include "pile.h"
#include "controleur.h"
#include "operateurmanager.h"

class QComputer : public QWidget{
    Q_OBJECT

    Pile* pile;
    Controleur* controleur;
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
    QPushButton* point;
    QPushButton* backspace;
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


    QVBoxLayout* paveNum;
    QHBoxLayout* paveNum1;
    QHBoxLayout* paveNum2;
    QHBoxLayout* paveNum3;
    QHBoxLayout* paveNum4;

    QPushButton* un;
    QPushButton* deux;
    QPushButton* trois;
    QPushButton* quatre;
    QPushButton* cinq;
    QPushButton* six;
    QPushButton* sept;
    QPushButton* huit;
    QPushButton* neuf;
    QPushButton* zero;



public :
    explicit QComputer(QWidget *parent = 0);
public slots:
    void refresh();
    void getNextCommande();
    void precedent();
    void suivant();

    void clearCommande(){commande->clear();}

    //SLOTS pour le pave numérique
    void unPressed(){commande->insert("1");}
    void deuxPressed(){commande->insert("2"); }
    void troisPressed(){commande->insert("3");}
    void quatrePressed(){commande->insert("4");}
    void cinqPressed(){commande->insert("5"); }
    void sixPressed(){commande->insert("6");}
    void septPressed(){commande->insert("7");}
    void huitPressed(){commande->insert("8");}
    void neufPressed(){commande->insert("9");}
    void zeroPressed(){commande->insert("0");}

    //SLOTS pour les opérateurs de base
    void plusPressed(){commande->insert("+");getNextCommande();}
    void moinsPressed(){commande->insert("-");getNextCommande();}
    void divPressed(){commande->insert("/");getNextCommande();}
    void mulPressed(){commande->insert("*");getNextCommande();}
    void pointPressed(){commande->insert(".");}

    //SLOTS pour les opérateurs numériques
    void divBPressed(){commande->insert("DIV");}
    void negPressed(){commande->insert("NEG");getNextCommande();}
    void denPressed(){commande->insert("DEN");}
    void numPressed(){commande->insert("NUM");}
    void ccomplexPressed(){commande->insert("$");getNextCommande();}
    void rePressed(){commande->insert("RE");}
    void imPressed(){commande->insert("IM");}

    //SLOTS pour les opérateurs logiques
    void andbPressed(){commande->insert("AND");}
    void orbPressed(){commande->insert("OR");}
    void notbPressed(){commande->insert("NOT");}
    void egalPressed(){commande->insert("=");}
    void diffPressed(){commande->insert("!=");getNextCommande();}
    void supPressed(){commande->insert(">");getNextCommande();}
    void infPressed(){commande->insert("<");getNextCommande();}
    void supegPressed(){commande->insert(">=");getNextCommande();}
    void infegPressed(){commande->insert("=<");getNextCommande();}

    //SLOTS pour les opérateurs conditionnels
    void iftPressed(){commande->insert("IFT");}

    //SLOTS pour les opérateurs de la pile
    void dupPressed(){commande->insert("DUP");}
    void dropPressed(){commande->insert("DROP");}
    void swapPressed(){commande->insert("SWAP");}
    void lastopPressed(){commande->insert("LASTOP");}
    void lastargPressed(){commande->insert("LASTARG");}
    void undoPressed(){precedent();}
    void redoPressed(){suivant();}

};

#endif // QCOMPUTER_H


