#include "qcomputer.h"

QComputer::QComputer(QWidget* parent):QWidget(parent){
    this->setFixedSize(900, 700);

    /** Layout principal **/

    boxcomplete = new QVBoxLayout(this);


    /** Layout du haut **/


    message = new QLineEdit(this);
    commande = new QLineEdit(this);
    pile=new Pile;
    controleur = new Controleur(litteraleManager::getInstance(), operateurManager::getInstance(), *pile);
    //clavier= new QVBoxLayout;//ajouter clavier � la couche

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

    /** Construction des layouts **/

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
    //controleur->commande(c);
    commande->clear();
}
