#include "qcomputer.h"

/****
 * Pour l'instant si on tape des chose sur le clavier virtuel, il faut cliquer sur la ligne de commande
 * si l'on veut valider la ligne par notre propre clavier
 *
 * Commencé pour le + à prendre en compte le fait qu'une fois cliqué on empile direct, à voir si ça marche
 ****/

QComputer::QComputer(QWidget* parent):QWidget(parent){
    this->setFixedSize(700, 650);

    /** Layout principal **/

    boxcomplete = new QVBoxLayout(this);


    /** Layout du haut **/


    message = new QLineEdit(this);
    commande = new QLineEdit(this);
    pile=new Pile;
    controleur = new Controleur(operateurManager::getInstance(), *pile);

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
    vuepile->setVerticalHeaderLabels(liste);                        //on redéfini les labels pour mettre les ":"


    // Allocation des cases du TableWidget

    for (unsigned int i=0 ; i<pile->getNbItemsToAffiche() ; i++)
        vuepile->setItem(i, 0, new QTableWidgetItem(""));


    couchehaut = new QVBoxLayout(this);
    couchehaut->addWidget(message);
    couchehaut->addWidget(vuepile);
    couchehaut->addWidget(commande);


    /** Layout du bas **/

    couchebas = new QHBoxLayout(this);

    /** Layout des opÃ©rateurs de bases **/

    plus = new QPushButton("+",this);
    moins = new QPushButton("-",this);
    div = new QPushButton("/",this);
    mul = new QPushButton("*",this);
    point = new QPushButton(".",this);
    entree = new QPushButton("EntrÃ©e",this);

    opbasique = new QVBoxLayout(this);
    opbasique->addWidget(plus);
    opbasique->addWidget(moins);
    opbasique->addWidget(div);
    opbasique->addWidget(mul);
    opbasique->addWidget(point);
    opbasique->addWidget(entree);

    /** Connexion des opérateurs de base **/

    connect(plus, SIGNAL(pressed()), this, SLOT(plusPressed()));
    connect(moins, SIGNAL(pressed()), this, SLOT(moinsPressed()));
    connect(div, SIGNAL(pressed()), this, SLOT(divPressed()));
    connect(mul, SIGNAL(pressed()), this, SLOT(mulPressed()));
    connect(point, SIGNAL(pressed()), this, SLOT(pointPressed()));
    connect(entree, SIGNAL(pressed()), this, SLOT(getNextCommande()));

    /** Layout des opÃ©rateurs numÃ©riques **/

    divB = new QPushButton("DIV",this);
    neg = new QPushButton("NEG",this);
    den = new QPushButton("DEN",this);
    num = new QPushButton("NUM",this);
    ccomplex = new QPushButton("$",this);
    re = new QPushButton("RE",this);
    im = new QPushButton("IM",this);

    opnum = new QVBoxLayout(this);
    opnum->addWidget(divB);
    opnum->addWidget(neg);
    opnum->addWidget(den);
    opnum->addWidget(num);
    opnum->addWidget(ccomplex);
    opnum->addWidget(re);
    opnum->addWidget(im);


    /** Connexion des opérateurs numériques **/

    connect(divB, SIGNAL(pressed()), this, SLOT(divBPressed()));
    connect(neg, SIGNAL(pressed()), this, SLOT(negPressed()));
    connect(den, SIGNAL(pressed()), this, SLOT(denPressed()));
    connect(num, SIGNAL(pressed()), this, SLOT(numPressed()));
    connect(ccomplex, SIGNAL(pressed()), this, SLOT(ccomplexPressed()));
    connect(re, SIGNAL(pressed()), this, SLOT(rePressed()));
    connect(im, SIGNAL(pressed()), this, SLOT(imPressed()));

    /** Layout des opÃ©rateurs logiques **/

    oplog = new QVBoxLayout(this);
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

    /** Connexion des opérateurs logiques **/

    connect(andb, SIGNAL(pressed()), this, SLOT(andbPressed()));
    connect(orb, SIGNAL(pressed()), this, SLOT(orbPressed()));
    connect(notb, SIGNAL(pressed()), this, SLOT(notbPressed()));
    connect(egal, SIGNAL(pressed()), this, SLOT(egalPressed()));
    connect(diff, SIGNAL(pressed()), this, SLOT(diffPressed()));
    connect(sup, SIGNAL(pressed()), this, SLOT(supPressed()));
    connect(inf, SIGNAL(pressed()), this, SLOT(infPressed()));
    connect(supeg, SIGNAL(pressed()), this, SLOT(supegPressed()));
    connect(infeg, SIGNAL(pressed()), this, SLOT(infegPressed()));

    /** Layout des opÃ©rateurs conditionnels **/

    opcond = new QVBoxLayout(this);
    ift = new QPushButton("IFT",this);

    opcond->addWidget(ift);

    /** Connexion des opérateurs conditionnels **/

    connect(ift, SIGNAL(pressed()), this, SLOT(iftPressed()));

    /** Layout des opÃ©rateurs pile **/

    oppile = new QVBoxLayout(this);
    dup = new QPushButton("DUP",this);
    drop = new QPushButton("DROP",this);
    swap = new QPushButton("SWAP",this);
    lastop = new QPushButton("LASTOP",this);
    lastarg = new QPushButton("LASTARG",this);
    undo = new QPushButton("UNDO",this);
    redo = new QPushButton("REDO",this);
    clear = new QPushButton("CLEAR",this);

    oppile->addWidget(dup);
    oppile->addWidget(drop);
    oppile->addWidget(swap);
    oppile->addWidget(lastop);
    oppile->addWidget(lastarg);
    oppile->addWidget(undo);
    oppile->addWidget(redo);
    oppile->addWidget(clear);

    /** Connexion des opérateurs de la pile **/

    connect(dup, SIGNAL(pressed()), this, SLOT(dupPressed()));
    connect(drop, SIGNAL(pressed()), this, SLOT(dropPressed()));
    connect(swap, SIGNAL(pressed()), this, SLOT(swapPressed()));
    connect(lastop, SIGNAL(pressed()), this, SLOT(lastopPressed()));
    connect(lastarg, SIGNAL(pressed()), this, SLOT(lastargPressed()));
    connect(undo, SIGNAL(pressed()), this, SLOT(undoPressed()));
    connect(redo, SIGNAL(pressed()), this, SLOT(redoPressed()));
    connect(clear, SIGNAL(pressed()), this, SLOT(clearCommande()));

    /** Layout du pavé numérique **/

    //Ligne 1
    paveNum1 = new QHBoxLayout(this);
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
    paveNum2 = new QHBoxLayout(this);
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
    paveNum3 = new QHBoxLayout(this);
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
    paveNum4 = new QHBoxLayout(this);
    zero = new QPushButton("0", this);
    //zero->setFixedSize(30,30);
    paveNum4->addWidget(zero);

    //PAVE complet
    paveNum = new QVBoxLayout(this);
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

    boxcomplete->addLayout(couchehaut);
    boxcomplete->addLayout(couchebas);


    message->setReadOnly(true);
    message->setStyleSheet("color: blue;"
                           "background-color: grey;"
                           "selection-color: grey;"
                           "selection-background-color: blue;");


    /*connecter que la commande emet signal return pressed
     * getnext commande */
        connect(commande, SIGNAL(returnPressed()),this,SLOT(getNextCommande()));
        connect(pile,SIGNAL(modificationEtat()),this,SLOT(refresh()));

        //connexion du pavé numérique à la ligne de commande
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

 //! \brief la fonction refresh() permet de mettre à jour l'affichage de la calculatrice en fct de ce que l'on a dans la pile
void QComputer::refresh(){//affichage etat pile

    //lÃ  on efface tout ce qu'il y a dans l'affichage la pile
    for(unsigned int i=0;i<pile->getNbItemsToAffiche(); i++){
        vuepile->item(i,0)->setText("");
    }
    unsigned int nb=0;
    /*ici le item est une fonction de Qt et pas notre classe item:
    *"Returns the item for the given row and column if one has been set; otherwise returns 0."
    * setText a besoin d'un string
    */
    for (Pile::iterator it=pile->begin(); nb<pile->getNbItemsToAffiche() && it!=pile->end();++it, ++nb)
        vuepile->item(pile->getNbItemsToAffiche()-nb-1,0)->setText((*it).affichage());

    //.. et message utilisateur
    message->setText(pile->getMessage());
    /*if(pile->getMessage()!=""){
        QSound bells("mysounds/bells.wav");
        bells.play();}*/

}


void QComputer::getNextCommande(){
    //si c'est un nombre empile si operateur on applique
    QString c=commande->text();
    controleur->commande(c);
    commande->clear();
}

