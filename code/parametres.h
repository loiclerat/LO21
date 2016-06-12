#ifndef PARAMETRES_H
#define PARAMETRES_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QCheckBox>
#include <QSpinBox>
#include "pile.h"

class Parametres : public QWidget{
    Q_OBJECT

    QCheckBox* son;
    QCheckBox* clavier;
    QSpinBox* nbitem;
    QPushButton* submit;
    QVBoxLayout* couche;

    unsigned int& clav;
    unsigned int& sons;

public:
    explicit Parametres(unsigned int& c, unsigned int& s, QWidget *parent = 0);

public slots:
    void submitPressed();
signals:
    void ferme();

};

#endif // PARAMETRES_H
