#ifndef PARAMETRES_H
#define PARAMETRES_H

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
#include <QCheckBox>
#include <QSpinBox>
#include "pile.h"
#include "controleur.h"
#include "operateurmanager.h"

class Parametres : public QWidget{
    Q_OBJECT

    QCheckBox* son;
    QCheckBox* clavier;
    QSpinBox* nbitem;
    QPushButton* submit;
    QVBoxLayout* couche;

public:
    explicit Parametres(QWidget *parent = 0);

public slots:
    void submitPressed();

};

#endif // PARAMETRES_H
