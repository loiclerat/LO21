#include "qcomputer.h"

/****
 * Pour l'instant si on tape des chose sur le clavier virtuel, il faut cliquer sur la ligne de commande
 * si l'on veut valider la ligne par notre propre clavier
 *
 * CommencÃ© pour le + ï¿½  prendre en compte le fait qu'une fois cliquÃ© on empile direct, ï¿½  voir si Ã§a marche
 ****/


QComputer::QComputer(QWidget* parent):QWidget(parent){
    this->setFixedSize(700, 650);

    /** Layout principal **/

    boxcomplete = new QVBoxLayout();

    /** Layout des parametres **/

    parametres = new QPushButton("Paramètres", this);
    coucheparametres = new QVBoxLayout();
    coucheparametres->addWidget(parametres);

    showClavier = 2;
    sons = 2;

    connect(parametres, SIGNAL(pressed()), this, SLOT(parametresPressed()));

    /** Layout du haut **/


    message = new QLineEdit();
    commande = new QLineEdit();
    pile=new Pile;
    controleur = &(Controleur::getInstance(pile));// new Controleur(operateurManager::getInstance(), *pile);

    vuepile = new QTableWidget(pile->getNbItemsToAffiche(),1,this);
    vuepile->horizontalHeader()->setVisible(false);
    vuepile->horizontalHeader()->setStretchLastSection(true);
    vuepile->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QStringList liste;
        for (unsigned int i=pile->getNbItemsToAffiche() ; i>0 ; i--){
            QString str = QString::number(i);                            //liste de string
            str+=" :";
            liste<<str;
        }
    vuepile->setVerticalHeaderLabels(liste);                        //on redÃ©fini les labels pour mettre les ":"


    annuler = new QAction(this);
    annuler->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z)); //dï¿½claration du raccourci
    connect(annuler, SIGNAL(triggered()), this, SLOT(precedent()));
    this->addAction(annuler);

    retablir = new QAction(this);
    retablir->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y)); //dï¿½claration du raccourci
    connect(retablir, SIGNAL(triggered()), this, SLOT(suivant()));
    this->addAction(retablir);

    // Allocation des cases du TableWidget

    for (unsigned int i=0 ; i<pile->getNbItemsToAffiche() ; i++)
        vuepile->setItem(i, 0, new QTableWidgetItem(""));


    couchehaut = new QVBoxLayout();
    couchehaut->addWidget(message);
    couchehaut->addWidget(vuepile);
    couchehaut->addWidget(commande);


    /** Layout du bas **/

    couchebas = new QHBoxLayout();

    /** Layout des opÃƒÂ©rateurs de bases **/

    plus = new QPushButton("+",this);
    moins = new QPushButton("-",this);
    div = new QPushButton("/",this);
    mul = new QPushButton("*",this);
    point = new QPushButton(".",this);
    entree = new QPushButton("Entrer",this);
    backspace = new QPushButton("Supprimer",this);

    opbasique = new QVBoxLayout();
    opbasique->addWidget(plus);
    opbasique->addWidget(moins);
    opbasique->addWidget(div);
    opbasique->addWidget(mul);
    opbasique->addWidget(point);
    opbasique->addWidget(entree);
    opbasique->addWidget(backspace);

    /** Connexion des opÃ©rateurs de base **/

    connect(plus, SIGNAL(pressed()), this, SLOT(plusPressed()));
    connect(moins, SIGNAL(pressed()), this, SLOT(moinsPressed()));
    connect(div, SIGNAL(pressed()), this, SLOT(divPressed()));
    connect(mul, SIGNAL(pressed()), this, SLOT(mulPressed()));
    connect(point, SIGNAL(pressed()), this, SLOT(pointPressed()));
    connect(entree, SIGNAL(pressed()), this, SLOT(getNextCommande()));
    connect(backspace, SIGNAL(pressed()), this, SLOT(backSpaceCommande()));

    /** Layout des opÃƒÂ©rateurs numÃƒÂ©riques **/

    mod = new QPushButton("MOD",this);
    divB = new QPushButton("DIV",this);
    neg = new QPushButton("NEG",this);
    den = new QPushButton("DEN",this);
    num = new QPushButton("NUM",this);
    ccomplex = new QPushButton("$",this);
    re = new QPushButton("RE",this);
    im = new QPushButton("IM",this);

    opnum = new QVBoxLayout();
    opnum->addWidget(mod);
    opnum->addWidget(divB);
    opnum->addWidget(neg);
    opnum->addWidget(den);
    opnum->addWidget(num);
    opnum->addWidget(ccomplex);
    opnum->addWidget(re);
    opnum->addWidget(im);


    /** Connexion des opÃ©rateurs numÃ©riques **/

    connect(mod, SIGNAL(pressed()), this, SLOT(modPressed()));
    connect(divB, SIGNAL(pressed()), this, SLOT(divBPressed()));
    connect(neg, SIGNAL(pressed()), this, SLOT(negPressed()));
    connect(den, SIGNAL(pressed()), this, SLOT(denPressed()));
    connect(num, SIGNAL(pressed()), this, SLOT(numPressed()));
    connect(ccomplex, SIGNAL(pressed()), this, SLOT(ccomplexPressed()));
    connect(re, SIGNAL(pressed()), this, SLOT(rePressed()));
    connect(im, SIGNAL(pressed()), this, SLOT(imPressed()));

    /** Layout des opÃƒÂ©rateurs logiques **/

    oplog = new QVBoxLayout();
    andb = new QPushButton("AND",this);
    orb = new QPushButton("OR",this);
    notb = new QPushButton("NOT",this);
    egal = new QPushButton("=",this);
    diff = new QPushButton("!=",this);
    sup = new QPushButton(">",this);
    inf = new QPushButton("<",this);
    supeg = new QPushButton(">=",this);
    infeg = new QPushButton("=<",this);

    oplog->addWidget(andb);
    oplog->addWidget(orb);
    oplog->addWidget(notb);
    oplog->addWidget(egal);
    oplog->addWidget(diff);
    oplog->addWidget(sup);
    oplog->addWidget(inf);
    oplog->addWidget(supeg);
    oplog->addWidget(infeg);

    /** Connexion des opÃ©rateurs logiques **/

    connect(andb, SIGNAL(pressed()), this, SLOT(andbPressed()));
    connect(orb, SIGNAL(pressed()), this, SLOT(orbPressed()));
    connect(notb, SIGNAL(pressed()), this, SLOT(notbPressed()));
    connect(egal, SIGNAL(pressed()), this, SLOT(egalPressed()));
    connect(diff, SIGNAL(pressed()), this, SLOT(diffPressed()));
    connect(sup, SIGNAL(pressed()), this, SLOT(supPressed()));
    connect(inf, SIGNAL(pressed()), this, SLOT(infPressed()));
    connect(supeg, SIGNAL(pressed()), this, SLOT(supegPressed()));
    connect(infeg, SIGNAL(pressed()), this, SLOT(infegPressed()));

    /** Layout des opÃƒÂ©rateurs conditionnels **/

    opcond = new QVBoxLayout();
    ift = new QPushButton("IFT",this);

    opcond->addWidget(ift);

    /** Connexion des opÃ©rateurs conditionnels **/

    connect(ift, SIGNAL(pressed()), this, SLOT(iftPressed()));

    /** Layout des opÃƒÂ©rateurs pile **/

    oppile = new QVBoxLayout();
    dup = new QPushButton("DUP",this);
    undo = new QPushButton("UNDO",this);
    redo = new QPushButton("REDO",this);
    clear = new QPushButton("CLEAR",this);

    oppile->addWidget(dup);
    oppile->addWidget(undo);
    oppile->addWidget(redo);
    oppile->addWidget(clear);

    /** Connexion des opÃ©rateurs de la pile **/

    connect(dup, SIGNAL(pressed()), this, SLOT(dupPressed()));
    connect(undo, SIGNAL(pressed()), this, SLOT(undoPressed()));
    connect(redo, SIGNAL(pressed()), this, SLOT(redoPressed()));
    connect(clear, SIGNAL(pressed()), this, SLOT(clearCommande()));

    /** Layout du pavÃ© numÃ©rique **/

    //Ligne 1
    paveNum1 = new QHBoxLayout();
    un = new QPushButton("1", this);
    un->setFixedSize(30,30);
    deux = new QPushButton("2", this);
    deux->setFixedSize(30,30);
    trois = new QPushButton("3", this);
    trois->setFixedSize(30,30);

    paveNum1->addWidget(un);
    paveNum1->addWidget(deux);
    paveNum1->addWidget(trois);

    //Ligne 2
    paveNum2 = new QHBoxLayout();
    quatre = new QPushButton("4", this);
    quatre->setFixedSize(30,30);
    cinq = new QPushButton("5", this);
    cinq->setFixedSize(30,30);
    six = new QPushButton("6", this);
    six->setFixedSize(30,30);

    paveNum2->addWidget(quatre);
    paveNum2->addWidget(cinq);
    paveNum2->addWidget(six);

    //Ligne 3
    paveNum3 = new QHBoxLayout();
    sept = new QPushButton("7", this);
    sept->setFixedSize(30,30);
    huit = new QPushButton("8", this);
    huit->setFixedSize(30,30);
    neuf = new QPushButton("9", this);
    neuf->setFixedSize(30,30);

    paveNum3->addWidget(sept);
    paveNum3->addWidget(huit);
    paveNum3->addWidget(neuf);

    //Ligne 4
    paveNum4 = new QHBoxLayout();
    zero = new QPushButton("0", this);
    //zero->setFixedSize(30,30);
    paveNum4->addWidget(zero);

    //PAVE complet
    paveNum = new QVBoxLayout();
    paveNum->addLayout(paveNum1);
    paveNum->addLayout(paveNum2);
    paveNum->addLayout(paveNum3);
    paveNum->addLayout(paveNum4);

    /** Construction des layouts **/

    couchebas->addLayout(paveNum);
    couchebas->addLayout(opbasique);
    couchebas->addLayout(opnum);
    couchebas->addLayout(oplog);
    couchebas->addLayout(opcond);
    couchebas->addLayout(oppile);

    /** Layout principal **/

    boxcomplete->addLayout(coucheparametres);
    boxcomplete->addLayout(couchehaut);
    boxcomplete->addLayout(couchebas);

    message->setReadOnly(true);
    message->setStyleSheet("color: white;"
                           "background-color: grey;"
                           "selection-color: grey;"
                           "selection-background-color: white;");


    /*connecter que la commande emet signal return pressed
     * getnext commande */
        connect(commande, SIGNAL(returnPressed()),this,SLOT(getNextCommande()));
        connect(pile,SIGNAL(modificationEtat()),this,SLOT(refresh()));

        //connexion du pavÃ© numÃ©rique ï¿½  la ligne de commande
        connect(un, SIGNAL(pressed()), this, SLOT(unPressed()));
        connect(deux, SIGNAL(pressed()), this, SLOT(deuxPressed()));
        connect(trois, SIGNAL(pressed()), this, SLOT(troisPressed()));
        connect(quatre, SIGNAL(pressed()), this, SLOT(quatrePressed()));
        connect(cinq, SIGNAL(pressed()), this, SLOT(cinqPressed()));
        connect(six, SIGNAL(pressed()), this, SLOT(sixPressed()));
        connect(sept, SIGNAL(pressed()), this, SLOT(septPressed()));
        connect(huit, SIGNAL(pressed()), this, SLOT(huitPressed()));
        connect(neuf, SIGNAL(pressed()), this, SLOT(neufPressed()));
        connect(zero, SIGNAL(pressed()), this, SLOT(zeroPressed()));

    setLayout(boxcomplete);
    setWindowTitle("UTComputer");
}

 //! \brief la fonction refresh() permet de mettre ï¿½  jour l'affichage de la calculatrice en fct de ce que l'on a dans la pile
void QComputer::refresh(){//affichage etat pile

    if (showClavier == 1){
        vueClavier(true);
        showClavier = 2;
    }
    else if (showClavier == 0){
        vueClavier(false);
        showClavier = -1;
    }

    while (vuepile->rowCount() > pile->getNbItemsToAffiche()){
        qDebug()<<vuepile->rowCount();
        vuepile->removeRow(0);
    }
    bool ajout = false;
    while (vuepile->rowCount() < pile->getNbItemsToAffiche()){
        vuepile->insertRow(vuepile->rowCount());
        vuepile->setItem(vuepile->rowCount()-1, 0, new QTableWidgetItem(""));
        qDebug()<<vuepile->rowCount();
        ajout = true;
    }
    if (ajout){
    QStringList liste;
        for (unsigned int i=pile->getNbItemsToAffiche() ; i>0 ; i--){
            QString str = QString::number(i);                            //liste de string
            str+=" :";
            liste<<str;
        }
    vuepile->setVerticalHeaderLabels(liste);                        //on redÃ©fini les labels pour mettre les ":"
    }

    //lÃƒ  on efface tout ce qu'il y a dans l'affichage la pile
    for(unsigned int i=0;i<pile->getNbItemsToAffiche(); i++){
        vuepile->item(i,0)->setText("");
    }
    unsigned int nb=0;
    for (Pile::iterator it=pile->begin(); nb<pile->getNbItemsToAffiche() && it!=pile->end();++it, ++nb)
        vuepile->item(pile->getNbItemsToAffiche()-nb-1,0)->setText((*it).affichage());

    //.. et message utilisateur
    message->setText(pile->getMessage());

    //! \todo Mettre le bon chemin pour la piste audio
    if (message->text() != "" && sons == 2){
        QSound alarm("code/Chewbacca.wav");  // Mettre le bon chemin si ï¿½a ne marche pas
        alarm.play();
    }

    if (sons == 1)
        sons = 2;
    else if (showClavier == 0)
        sons = -1;
}


void QComputer::getNextCommande(){
    //si c'est un nombre empile si operateur on applique
    QString c=commande->text();
    controleur->commande(c);
    commande->clear();
}


void QComputer::precedent(){
    controleur->loadPrecedent();
    refresh();
}

void QComputer::suivant(){
    controleur->loadSuivant();
    refresh();
}



// Affichage de la fenêtre de gestion des paramètres
void QComputer::parametresPressed(){
    para = new Parametres(showClavier, sons);
    connect(para, SIGNAL(ferme()), this, SLOT(refresh()));
    para->show();
}

void QComputer::vueClavier(bool visible){

    plus->setVisible(visible);
    moins->setVisible(visible);
    mul->setVisible(visible);
    div->setVisible(visible);
    point->setVisible(visible);
    backspace->setVisible(visible);
    entree->setVisible(visible);
    mod->setVisible(visible);
    divB->setVisible(visible);
    neg->setVisible(visible);
    den->setVisible(visible);
    num->setVisible(visible);
    ccomplex->setVisible(visible);
    re->setVisible(visible);
    im->setVisible(visible);
    andb->setVisible(visible);
    orb->setVisible(visible);
    notb->setVisible(visible);
    egal->setVisible(visible);
    diff->setVisible(visible);
    sup->setVisible(visible);
    inf->setVisible(visible);
    supeg->setVisible(visible);
    infeg->setVisible(visible);
    ift->setVisible(visible);
    dup->setVisible(visible);
    undo->setVisible(visible);
    redo->setVisible(visible);
    clear->setVisible(visible);
    un->setVisible(visible);
    deux->setVisible(visible);
    trois->setVisible(visible);
    quatre->setVisible(visible);
    cinq->setVisible(visible);
    six->setVisible(visible);
    sept->setVisible(visible);
    huit->setVisible(visible);
    neuf->setVisible(visible);
    zero->setVisible(visible);
}
