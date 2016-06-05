#include "qcomputer.h"

/****
 * Pour l'instant si on tape des chose sur le clavier virtuel, il faut cliquer sur la ligne de commande
 * si l'on veut valider la ligne par notre propre clavier
 ****/

QComputer::QComputer(QWidget* parent):QWidget(parent){
    this->setFixedSize(700, 650);

    /** Layout principal **/

    boxcomplete = new QVBoxLayout(this);


    /** Layout du haut **/


    message = new QLineEdit(this);
    commande = new QLineEdit(this);
    pile=new Pile;
    controleur = new Controleur(litteraleManager::getInstance(), operateurManager::getInstance(), *pile);

    vuepile = new QTableWidget(9,2,this);
    vuepile->horizontalHeader()->setVisible(false);
    vuepile->horizontalHeader()->setStretchLastSection(true);
    vuepile->setEditTriggers(QAbstractItemView::NoEditTriggers);

    couchehaut = new QVBoxLayout(this);
    couchehaut->addWidget(message);
    couchehaut->addWidget(vuepile);
    couchehaut->addWidget(commande);


    /** Layout du bas **/

    couchebas = new QHBoxLayout(this);

    /** Layout des opérateurs de bases **/

    plus = new QPushButton("+",this);
    moins = new QPushButton("-",this);
    div = new QPushButton("/",this);
    mul = new QPushButton("*",this);
    entree = new QPushButton("Entrée",this);

    opbasique = new QVBoxLayout(this);
    opbasique->addWidget(plus);
    opbasique->addWidget(moins);
    opbasique->addWidget(div);
    opbasique->addWidget(mul);
    opbasique->addWidget(entree);

    /** Connexion des op�rateurs de base **/

    connect(plus, SIGNAL(pressed()), this, SLOT(plusPressed()));
    connect(moins, SIGNAL(pressed()), this, SLOT(moinsPressed()));
    connect(div, SIGNAL(pressed()), this, SLOT(divPressed()));
    connect(mul, SIGNAL(pressed()), this, SLOT(mulPressed()));
    connect(entree, SIGNAL(pressed()), this, SLOT(getNextCommande()));

    /** Layout des opérateurs numériques **/

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


    /** Connexion des op�rateurs num�riques **/

    connect(divB, SIGNAL(pressed()), this, SLOT(divBPressed()));
    connect(neg, SIGNAL(pressed()), this, SLOT(negPressed()));
    connect(den, SIGNAL(pressed()), this, SLOT(denPressed()));
    connect(num, SIGNAL(pressed()), this, SLOT(numPressed()));
    connect(ccomplex, SIGNAL(pressed()), this, SLOT(ccomplexPressed()));
    connect(re, SIGNAL(pressed()), this, SLOT(rePressed()));
    connect(im, SIGNAL(pressed()), this, SLOT(imPressed()));

    /** Layout des opérateurs logiques **/

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

    /** Connexion des op�rateurs logiques **/

    connect(divB, SIGNAL(pressed()), this, SLOT(divBPressed()));
    connect(neg, SIGNAL(pressed()), this, SLOT(negPressed()));
    connect(den, SIGNAL(pressed()), this, SLOT(denPressed()));
    connect(num, SIGNAL(pressed()), this, SLOT(numPressed()));
    connect(ccomplex, SIGNAL(pressed()), this, SLOT(ccomplexPressed()));
    connect(re, SIGNAL(pressed()), this, SLOT(rePressed()));
    connect(im, SIGNAL(pressed()), this, SLOT(imPressed()));

    /** Layout des opérateurs conditionnels **/

    opcond = new QVBoxLayout(this);
    ift = new QPushButton("IFT",this);

    opcond->addWidget(ift);

    /** Layout des opérateurs pile **/

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


    /** Layout du pav� num�rique **/

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

        //connexion du pav� num�rique � la ligne de commande
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

 //! \brief la fonction refresh() permet de mettre � jour l'affichage de la calculatrice en fct de ce que l'on a dans la pile
void QComputer::refresh(){
    //affichage etat pile

    //l�  on efface tout ce qu'il y a dans l'affichage la pile
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

}


void QComputer::getNextCommande(){
    //si c'est un nombre empile si operateur on applique
    QString c=commande->text();
    controleur->commande(c);
    commande->clear();
}

