/**
\file qcomputer.h
\date 03/06/2016
\author Lo�c Lerat, Andr�a Vibert, Th�o Hordequin
\version 1.0
\brief  Interface graphique sur Qt permettant l'affichage de la calculatrice


Description de la classe QComputer
**/

#ifndef QCOMPUTER_H
#define QCOMPUTER_H

#include <QKeySequence>
#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QDebug>
#include <QPushButton>
#include <QSound>
#include <QRegExp>
#include <QAction>
#include "pile.h"
#include "controleur.h"
#include "operateurmanager.h"
#include "parametres.h"


//! \class QObject
//! \brief Fenetre graphique sur Qt servant d'interface entre l'utilisateur et notre programme
class QComputer : public QWidget{
    Q_OBJECT

    //! \brief Pointeur vers la pile pour communiquer avec elle, notamment pour les messages d'erreur
    Pile* pile;
    //! \brief Pointeur vers le controleur qui va g�rer notre programme
    Controleur* controleur;
    //! \brief Ligne permettant d'afficher les messages d'erreurs sans que l'on puisse les modifier
    QLineEdit* message;
    //! \brief Ligne dre commande sur laquelle l'utilisateur rentre les instructions
    QLineEdit* commande;
    //! \brief Vision
    QTableWidget* vuepile;

    //! \brief Layout de l'int�gralite de la fen�tre
    QVBoxLayout* boxcomplete;

    //! \brief Couche permettant l'acc�s � la fen�tre de param�trage de l'interface gr�ce � un boutton cliquable
    QVBoxLayout* coucheparametres;
    QPushButton* parametres;
    Parametres* para;

    QVBoxLayout* couchehaut;
    QHBoxLayout* couchebas;
    //! \brief Ensemble des op�rateurs basiques
    QVBoxLayout* opbasique;
    QPushButton* plus;
    QPushButton* moins;
    QPushButton* mul;
    QPushButton* div;
    QPushButton* point;
    //! \brief Permet de supprimer le dernier symbole saisi sur la ligne de commande
    QPushButton* backspace;
    //! \brief Soumet la ligne de commande au controleur du programme
    QPushButton* entree;

//! \brief Ensemble des op�rateurs num�riques
    QVBoxLayout* opnum;
    QPushButton* mod;
    QPushButton* divB;
    QPushButton* neg;
    QPushButton* den;
    QPushButton* num;
    QPushButton* ccomplex;
    QPushButton* re;
    QPushButton* im;

//! \brief Ensemble des op�rateurs logiques
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

    //! \brief Op�rateur permettant d'�valuer le deuxi�me �l�ment d�pil� sous condition sur le premier argument


//! \brief Op�rateurs de pile et op�rateurs conditionnels
    QVBoxLayout* oppile;

   // QVBoxLayout* opcond;
    QPushButton* ift;
    //! \brief DUP pour empiler la litt�rale qui est sur le dessus de la pile
    QPushButton* dup;
    QPushButton* drop;
    QPushButton* swap;
    QPushButton* lastop;
    QPushButton* lastarg;
    //! \brief UNDO pour retouner � l'�tat pr�c�dent de la pile
    QPushButton* undo;
    //! \brief REDO pour r�tablir l'�tat suivant de la pile
    QPushButton* redo;
    //! \brief CLEAR pour nettoyer tout ce qui se trouve dans la ligne de saisie de texte
    QPushButton* clear;

//! \brief Pav� num�rique permettant de saisir tous les chiffres
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


    //! \brief Correspond � un UNDO, permet de signaler au controleur un retour � l'�tat pr�c�dent de la pile
    QAction* annuler;
    //! \brief Evenement permettant de faire un UNDO (action annuler pr�c�dente) gr�ce au raccourci clavier Ctrl + Z
    QKeyEvent* ctrlZ;
    QAction* retablir;

    unsigned int showClavier;
    unsigned int sons;



public :
    explicit QComputer(QWidget *parent = 0);

public slots:
    void refresh();
    void getNextCommande();
    void precedent();
    void suivant();

    void clearCommande(){commande->clear();}
    void backSpaceCommande(){commande->backspace();}

    void vueClavier(bool visible);

    void parametresPressed();

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
    void modPressed(){commande->insert("MOD");getNextCommande();}
    void divBPressed(){commande->insert("DIV");getNextCommande();}
    void negPressed(){commande->insert("NEG");getNextCommande();}
    void denPressed(){commande->insert("DEN");getNextCommande();}
    void numPressed(){commande->insert("NUM");getNextCommande();}
    void ccomplexPressed(){commande->insert("$");getNextCommande();}
    void rePressed(){commande->insert("RE");getNextCommande();}
    void imPressed(){commande->insert("IM");getNextCommande();}

    //SLOTS pour les opérateurs logiques
    void andbPressed(){commande->insert("AND");getNextCommande();}
    void orbPressed(){commande->insert("OR");getNextCommande();}
    void notbPressed(){commande->insert("NOT");getNextCommande();}
    void egalPressed(){commande->insert("=");getNextCommande();}
    void diffPressed(){commande->insert("!=");getNextCommande();}
    void supPressed(){commande->insert(">");getNextCommande();}
    void infPressed(){commande->insert("<");getNextCommande();}
    void supegPressed(){commande->insert(">=");getNextCommande();}
    void infegPressed(){commande->insert("=<");getNextCommande();}

    //SLOTS pour les opérateurs conditionnels
    void iftPressed(){commande->insert("IFT");getNextCommande();}

    //SLOTS pour les opérateurs de la pile
    void dupPressed(){commande->insert("DUP");getNextCommande();}
    void dropPressed(){commande->insert("DROP");getNextCommande();}
    void swapPressed(){commande->insert("SWAP");getNextCommande();}
    void lastopPressed(){commande->insert("LASTOP");getNextCommande();}
    void lastargPressed(){commande->insert("LASTARG");getNextCommande();}
    void undoPressed(){precedent();}
    void redoPressed(){suivant();}

};

#endif // QCOMPUTER_H


