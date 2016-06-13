﻿/**
\file qcomputer.h
\date 03/06/2016
\author Loïc Lerat, Andréa Vibert, Théo Hordequin
\version 1.0
\brief  Interface graphique sur Qt permettant l'affichage de la calculatrice


Description de la classe QComputer, ses attributs, slots et méthodes
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
    //! \brief Pointeur vers le controleur qui va gérer notre programme
    Controleur* controleur;
    //! \brief Ligne permettant d'afficher les messages d'erreurs sans que l'on puisse les modifier
    QLineEdit* message;
    //! \brief Ligne de commande sur laquelle l'utilisateur rentre les instructions
    QLineEdit* commande;
    //! \brief Vision de la pile en fonction du nombre de ligne à afficher
    QTableWidget* vuepile;

    //! \brief Layout de l'intégralite de la fenêtre
    QVBoxLayout* boxcomplete;

    //! \brief Couche permettant l'accès à la fenêtre de paramétrage de l'interface grâce à un boutton cliquable
    QVBoxLayout* coucheparametres;
    QPushButton* parametres;
    Parametres* para;

    QVBoxLayout* couchehaut;
    QHBoxLayout* couchebas;
    //! \brief Ensemble des opérateurs basiques
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

//! \brief Ensemble des opérateurs numériques
    QVBoxLayout* opnum;
    QPushButton* mod;
    QPushButton* divB;
    QPushButton* neg;
    QPushButton* den;
    QPushButton* num;
    QPushButton* ccomplex;
    QPushButton* re;
    QPushButton* im;

//! \brief Ensemble des opérateurs logiques
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



//! \brief Opérateurs de pile et opérateurs conditionnels
    QVBoxLayout* oppile;
    //! \brief Opérateur permettant d'évaluer le deuxième élément dépilé sous condition sur le premier argument
    QPushButton* ift;
    //! \brief DUP pour empiler la littérale qui est sur le dessus de la pile
    QPushButton* dup;
    //! \brief UNDO pour retouner à l'état précédent de la pile
    QPushButton* undo;
    //! \brief REDO pour rétablir l'état suivant de la pile
    QPushButton* redo;
    //! \brief CLEAR pour nettoyer tout ce qui se trouve dans la ligne de saisie de texte
    QPushButton* clear;
    //! \brief EVAL pour évaluer une littérale Programme
    QPushButton* eval;

//! \brief Pavé numérique permettant de saisir tous les chiffres
    QVBoxLayout* paveNum;
    QHBoxLayout* paveNum1;
    QHBoxLayout* paveNum2;
    QHBoxLayout* paveNum3;
    QHBoxLayout* paveNum4;
    QHBoxLayout* paveNum5;
    QHBoxLayout* paveNum6;

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
    QPushButton* crochetDroit;
    QPushButton* crochetGauche;
    QPushButton* space;


    //! \brief Correspond à un UNDO, permet de signaler au controleur un retour à l'état précédent de la pile
    QAction* annuler;
    //! \brief Evenement permettant de faire un UNDO (action annuler précédente) grâce au raccourci clavier Ctrl + Z
    QKeyEvent* ctrlZ;
    QAction* retablir;

    //! \brief Etat de l'affichage du clavier (2 : visible, -1 : caché, 1 : en cours d'affichage, 0 en cours masquage)
    unsigned int showClavier;
    //! \brief Etat de l'activation des sons (2 : activés, -1 : désactivés, 1 : en cours d'activation, 0 en cours de désactivation)
    unsigned int sons;



public :
    //! \brief Constructeur
    explicit QComputer(QWidget *parent = 0);

public slots:
    //! \brief Rafraîchit l'affichage de la pile
    void refresh();
    //! \brief Récupère la commande entrée par l'utilisateur et appelle le Controleur pour effectuer les traitements
    void getNextCommande();
    //! \brief Revenir à l'étape précédente
    void precedent();
    //! \brief Revenir à l'étape suivante
    void suivant();

    //! \brief Effacement de la ligne de commande
    void clearCommande(){commande->clear();}
    //! \brief Effacement du dernier caractère de la ligne de commande
    void backSpaceCommande(){commande->backspace();}

    //! \brief Affichage ou non du clavier
    void vueClavier(bool visible);

    //! \brief Affichage de la fenêtre d'édition des paramètres
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
    void crochetGauchePressed(){commande->insert("[ ");}
    void crochetDroitPressed(){commande->insert(" ]");}
    void spacePressed(){commande->insert(" ");}

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
    void evalPressed(){commande->insert("EVAL");getNextCommande();}
    void undoPressed(){precedent();}
    void redoPressed(){suivant();}

};

#endif // QCOMPUTER_H


