/**
\file operateur.cpp
\date 03/06/2016
\author Loïc Lerat, Andréa Vibert, Théo Hordequin
\version 1.0

Définitions des méthodes des classes d'Opérateurs

**/

#include "operateur.h"
#include "controleur.h"


/************************** + : addition ******************************************/
litterale& add::traitement(litterale& a, litterale& b)
{

    littEntiere* ent1 = dynamic_cast<littEntiere*>(&a);
    littrat* rat1 = dynamic_cast<littrat*>(&a);
    littReelle* ree1 = dynamic_cast<littReelle*>(&a);
    littcomplexe* comp1 = dynamic_cast<littcomplexe*>(&a);
    littNumerique* lta1 = dynamic_cast<littNumerique*>(&b);
    littcomplexe* lta2 = dynamic_cast<littcomplexe*>(&b);

    if (ent1 != 0) {
        if (lta1 != 0) {
            littNumerique* res = *(ent1) + lta1;
            return *res;
        }
        else {
            littnumber* res = *(ent1) + lta2;
            return *res;
        }
    }
    else if (rat1 != 0) {
        if (lta1 != 0) {
            littNumerique* res = *(rat1) + lta1;
            return *res;
        }
        else {
            littnumber* res = *(rat1) + lta2;
            return *res;
        }
    }
    else if (ree1 != 0) {
        if (lta1 != 0) {
            littNumerique* res = *(ree1) + lta1;
            return *res;
        }
        else {
            littnumber* res = *(ree1) + lta2;
            return *res;
        }
    }
    else if (comp1 != 0) {
        if (lta1 != 0) {
            littnumber* res = *(comp1) + lta1;
            return *res;
        }
        else {
            littnumber* res = *(comp1) + lta2;
            return *res;
        }
    }
    else throw ComputerException("Format incompatible du premier argument");
}

/******************* - : Soustraction **************************************/

litterale& sous::traitement(litterale& a, litterale& b)
{
    littEntiere* ent1 = dynamic_cast<littEntiere*>(&a);
    littrat* rat1 = dynamic_cast<littrat*>(&a);
    littReelle* ree1 = dynamic_cast<littReelle*>(&a);
    littcomplexe* comp1 = dynamic_cast<littcomplexe*>(&a);

    littNumerique* lta1 = dynamic_cast<littNumerique*>(&b);
    littcomplexe* lta2 = dynamic_cast<littcomplexe*>(&b);

    // si a est un entier et que lta1 est bien une litterale numerique
    if (ent1 != 0) {
        if (lta1 != 0) {
            littNumerique* res = *(ent1)-lta1;
            return *res;
        }
        else {
            littnumber* res = *(ent1)-lta2;
            return *res;
        }
    }
    else if (rat1 != 0) {
        if (lta1 != 0) {
            littNumerique* res = *(rat1)-lta1;
            return *res;
        }
        else {
            littnumber* res = *(rat1)-lta2;
            return *res;
        }
    }
    else if (ree1 != 0) {
        if (lta1 != 0) {
            littNumerique* res = *(ree1)-lta1;
            return *res;
        }
        else {
            littnumber* res = *(ree1)-lta2;
            return *res;
        }
    }
    else if (comp1 != 0) {
        if (lta1 != 0) {
            littnumber* res = *(comp1)-lta1;
            return *res;
        }
        else {
            littnumber* res = *(comp1)-lta2;
            return *res;
        }
    }
    else throw ComputerException("Format incompatible du premier argument");
}

/************** * : multiplication *******************************************/

litterale& mul::traitement(litterale &a, litterale &b){

    littEntiere* ent1 = dynamic_cast<littEntiere*>(&a);
    littrat* rat1 = dynamic_cast<littrat*>(&a);
    littReelle* ree1 = dynamic_cast<littReelle*>(&a);
    littcomplexe* comp1 = dynamic_cast<littcomplexe*>(&a);

    littNumerique* lta1 = dynamic_cast<littNumerique*>(&b);
    littcomplexe* lta2 = dynamic_cast<littcomplexe*>(&b);

    //si a est un entier et que ltb est bien une litterale numerique
    if(ent1 != 0){
        if(lta1!=0){
            littNumerique* res =  *(ent1)*lta1;
            return *res;
        }
        else{
            littnumber* res = *(ent1)*lta2;
            return *res;
        }
    }
    else
        if(rat1 != 0)
        {
            if(lta1!=0){
                littNumerique* res =  *(rat1)*lta1;
                return *res;
            }else{
                littnumber* res = *(rat1)*lta2;
                return *res;
            }
        }
        else
            if(ree1 != 0){
                if(lta1!=0){
                    littNumerique* res =  *(ree1)*lta1;
                    return *res;
                }else{
                    littnumber* res = *(ree1)*lta2;
                    return *res;
                }
            }
            else
                if(comp1 != 0){
                    if(lta1!=0){
                        littnumber* res =  *(comp1)*lta1;
                        return *res;
                    }else{
                        littnumber* res = *(comp1)*lta2;
                        return *res;
                    }
                }
                else throw ComputerException("Format incompatible du premier argument");
}

/************** / : division normale ***************************************/
litterale& divs::traitement(litterale &a, litterale &b){

    littEntiere* ent1 = dynamic_cast<littEntiere*>(&a);
    littrat* rat1 = dynamic_cast<littrat*>(&a);
    littReelle* ree1 = dynamic_cast<littReelle*>(&a);
    littcomplexe* comp1 = dynamic_cast<littcomplexe*>(&a);

    littNumerique* lta1 = dynamic_cast<littNumerique*>(&b);
    littcomplexe* lta2 = dynamic_cast<littcomplexe*>(&b);

    if(ent1 != 0){
        if(lta1!=0){
            littNumerique* res =  *(ent1)/lta1;
            return *res;
        }
        else{
            littnumber* res = *(ent1)/lta2;
            return *res;
        }
    }
    else{
        if(rat1 != 0)
        {
            if(lta1!=0){
                littNumerique* res =  *(rat1)/lta1;
                return *res;
            }else{
                littnumber* res = *(rat1)/lta2;
                return *res;
            }
        }
        else{
            if(ree1 != 0){
                if(lta1!=0){
                    littNumerique* res =  *(ree1)/lta1;
                    return *res;
                }else{
                    littnumber* res = *(ree1)/lta2;
                    return *res;
                }
            }
            else{
                if(comp1 != 0){
                    if(lta1!=0){
                        littnumber* res =  *(comp1)/lta1;
                        return *res;
                    }else{
                        littnumber* res = *(comp1)/lta2;
                        return *res;
                    }
                }
                else  throw ComputerException("Format incompatible du premier argument");
            }
        }
    }
}
/***************** NEG : négatif **************************/

litterale& neg::traitement(litterale &a){

    littnumber* b = dynamic_cast<littnumber*>(&a);

    if(b != 0)
    {// Si la littérale sur laquelle est le NEG est une littérale number alors on fait les calculs pour avoir l'opposé
        littEntiere* ent1 = dynamic_cast<littEntiere*>(&a);
        littrat* rat1 = dynamic_cast<littrat*>(&a);
        littReelle* ree1 = dynamic_cast<littReelle*>(&a);
        littcomplexe* comp1 = dynamic_cast<littcomplexe*>(&a);

        if(ent1!=0){//si c'est un entier nouvelle littérale entière avec l'opposé en valeur
            littEntiere* res= new littEntiere(-1*ent1->getValeur());
            return *res;
        }
        if(rat1!=0){//si c'est un rationnel nouvelle littérale rationnelle avec l'opposé en valeur
            littrat* res= new littrat(-1*rat1->getNum());
            return *res;
        }
        if(ree1!=0){//si c'est un entier nouvelle littérale réelle avec l'opposé de la partie entière
            littReelle* res= new littReelle(-1*ree1->getEntiere(),-1*ree1->getDecimale());
            return *res;
        }
        if(comp1!=0){//si c'est un entier nouvelle littérale entière avec l'opposé en valeur
            littEntiere x(-1);
            littNumerique * temp1 = x*(comp1->getPartRe()); //construction de cette nouvelle littNumerique dans la surcharge d'operateur * de littEntiere
            littNumerique * temp2 = x*(comp1->getPartIm());
            littcomplexe* res= new littcomplexe(temp1,temp2);
            return *res;
        }
    }else throw ComputerException("Ce n'est pas un nombre !");
}


/**************** $ : complexes ************************/

litterale& dollar::traitement(litterale &a, litterale &b){

    littNumerique* lta1 = dynamic_cast<littNumerique*>(&a);
    littNumerique* lta2 = dynamic_cast<littNumerique*>(&b);

    if(lta1 != 0){
        if(lta2 != 0){
            littcomplexe* res = new littcomplexe(lta1,lta2);
            return *res;
        }
        else throw ComputerException("Le second argument n'est pas une litterale numerique");
    }
    else throw ComputerException("Le premier argument n'est pas une litterale numerique");
}

/*******************DEN : Denominateur**************************************/
litterale& den::traitement(litterale &a){

    littrat* rat = dynamic_cast<littrat*>(&a);
    littEntiere* ent = dynamic_cast<littEntiere*>(&a);

    if(rat != 0)
    {
        littEntiere* t = new littEntiere(rat->getDen());
        return *t;
    }else if(ent!=0){
        littEntiere* t = new littEntiere(1);
        return *t;
    }
    throw ComputerException("Cet objet n'a pas de dénominateur (réelle ou complexe)");
}

/***************DIV : Division entiere **************************************/
litterale& divent::traitement(litterale &a, litterale &b){

    littEntiere* ent1 = dynamic_cast<littEntiere*>(&a);
    littNumerique* ent2 = dynamic_cast<littNumerique*>(&b);

    if(ent1 != 0 && ent2!=0)
    {
        littNumerique* res =  (*(ent1)/ent2);
        littrat* rat1 = dynamic_cast<littrat*>(res);
        if(rat1 != 0){
            int a = rat1->getNum()/rat1->getDen();
            littEntiere* resf = new littEntiere(a);
            return *resf;
        }
        else  throw ComputerException("Format incompatible du second argument, nécessite entier");
    }else  throw ComputerException("Format incompatible du second argument, nécessite entier");
}

/******************* MOD : Modulo *****************************/


litterale& mod::traitement(litterale &a, litterale &b){

    littEntiere* ent1 = dynamic_cast<littEntiere*>(&a);
    littNumerique* ent2 = dynamic_cast<littNumerique*>(&b);

    if(ent1 != 0 && ent2!=0){
            littNumerique* res =  (*(ent1)/ent2);
            littrat* rat1 = dynamic_cast<littrat*>(res);
                if(rat1 != 0){
                    littEntiere* resf = new littEntiere(ent1->getValeur()%rat1->getDen());
                    return *resf;
                }else throw ComputerException("Format incompatible du second argument, nécessite entier");
     }else throw ComputerException("Format incompatible du second argument, nécessite entier");
}
/************************ NUM : Numérateur *****************************/

litterale& num::traitement(litterale &a){

    littrat* b = dynamic_cast<littrat*>(&a);
    littEntiere *c=dynamic_cast<littEntiere*>(&a);

    if(b != 0)
    {
        littEntiere* t =  new littEntiere(b->getNum());
        return *t;
    }
    else{
        if(c!=0){
            littEntiere* t =  new littEntiere(c->getValeur());
            return *t;
        }
        else throw ComputerException("On ne peut pas retourner le numérateur de cette littérale.");
    }
}

/*********************** IM : partie imaginaire *********************/
litterale& opim::traitement(litterale& a)
{

    littNumerique* num = dynamic_cast<littNumerique*>(&a);
    littcomplexe* comp = dynamic_cast<littcomplexe*>(&a);

    if (comp != 0) {
        return *(comp->getPartIm());
    }
    else if (num != 0) {
        littEntiere* x = new littEntiere(0);
        return *x;
    }
    else throw ComputerException("Ce n'est pas un nombre !");
}
/***************** RE : Partie réelle ********************************/

litterale& opre::traitement(litterale& a)
{

    littNumerique* num = dynamic_cast<littNumerique*>(&a);
    littcomplexe* comp = dynamic_cast<littcomplexe*>(&a);

    if (comp != 0) {
        return *(comp->getPartRe());
    }
    else if (num != 0) {
        return *num;
    }
    else throw ComputerException("Ce n'est pas un nombre!");
}


/**************** AND : ET logique **********************************/

litterale& opand::traitement(litterale& a, litterale& b)
{

    littnumber* num1 = dynamic_cast<littnumber*>(&a);
    littnumber* num2 = dynamic_cast<littnumber*>(&b);

    if (num1 != 0 && num2 != 0) {
        if (num1->isNull() == false && num2->isNull()==false) {
            littEntiere* ret = new littEntiere(1);
            return *ret;
        }
        else {
            littEntiere* ret = new littEntiere(0);
            return *ret;
        }
    }
    else throw ComputerException("Format incompatible des argument, nécessite un nombre");
}

/***************** OR : OU logique *******************************/

litterale& opor::traitement(litterale& a, litterale& b)
{
    littnumber* num1 = dynamic_cast<littnumber*>(&a);
    littnumber* num2 = dynamic_cast<littnumber*>(&b);

    if (num1 != 0 && num2 != 0) {
        if (num1->isNull() == false || num2->isNull()==false) {
            littEntiere* ret = new littEntiere(1);
            return *ret;
        }
        else {
            littEntiere* ret = new littEntiere(0);
            return *ret;
        }
    }
    else throw ComputerException("Format incompatible des argument, nécessite un nombre");
}


/************** NOT : NON logique **********************************/
litterale& opnot::traitement(litterale& a)
{
    littnumber* num1 = dynamic_cast<littnumber*>(&a);

    if (num1 != 0) {
        if (num1->isNull()==true) {
            littEntiere* ret = new littEntiere(1);
            return *ret;
        }
        else {
            littEntiere* ret = new littEntiere(0);
            return *ret;
        }
    }
    else throw ComputerException("Format incompatible des argument, nécessite un nombre");
}

/*************** = : Egalité *************************************/

litterale& opegal::traitement(litterale& a, litterale& b)
{

    littnumber* num1 = dynamic_cast<littnumber*>(&a);
    littnumber* num2 = dynamic_cast<littnumber*>(&b);

    if (num1 != 0 && num2 != 0) {
        littnumber* res = (*(num1)-num2);
        if (res->isNull() == true) {
            littEntiere* ret = new littEntiere(1);
            return *ret;
        }
        else {
            littEntiere* ret = new littEntiere(0);
            return *ret;
        }
    }
    else throw ComputerException("Format incompatible des argument, nécessite un nombre");
}

/************** != : différence ***********************************/


litterale& opdiff::traitement(litterale& a, litterale& b)
{

    littnumber* num1 = dynamic_cast<littnumber*>(&a);
    littnumber* num2 = dynamic_cast<littnumber*>(&b);

    if (num1 != 0 && num2 != 0) {
        littnumber* res = (*(num1)-(num2));
        if (res->isNull() == false) { //si la différence entre les deux n'est pas nulle alors les deux elem sont bien differents
            littEntiere* ret = new littEntiere(1);
            return *ret;
        }
        else {
            littEntiere* ret = new littEntiere(0);
            return *ret;
        }
    }
    else throw ComputerException("Format incompatible des argument, nécessite un nombre");
}

/************* <= : opérateur inférieur ou égal ******************/

litterale& opegalinf::traitement(litterale& a, litterale& b)
{

    littnumber* num1 = dynamic_cast<littnumber*>(&a);
    littnumber* num2 = dynamic_cast<littnumber*>(&b);

    if (num1 != 0 && num2 != 0) {
        littnumber* res = (*(num1)-(num2));
        if (res->isPos() == false || res->isNull() == true) {
            littEntiere* ret = new littEntiere(1);
            return *ret;
        }
        else {
            littEntiere* ret = new littEntiere(0);
            return *ret;
        }
    }
    else throw ComputerException("Format incompatible des argument, nécessite un nombre");
}

/************ => : operateur egal ou supérieur *******************/
litterale& opegalsup::traitement(litterale& a, litterale& b)
{

    littnumber* num1 = dynamic_cast<littnumber*>(&a);
    littnumber* num2 = dynamic_cast<littnumber*>(&b);

    if (num1 != 0 && num2 != 0) {
        littnumber* res = (*(num1)-(num2));
        if (res->isPos() == true || res->isNull()==true) {
            littEntiere* ret = new littEntiere(1);
            return *ret;
        }
        else {
            littEntiere* ret = new littEntiere(0);
            return *ret;
        }
    }
    else throw ComputerException("Format incompatible des argument, nécessite un nombre");
}

/**************** > : superiorite *************************************/

litterale& opinf::traitement(litterale& a, litterale& b)
{
    littnumber* num1 = dynamic_cast<littnumber*>(&a);
    littnumber* num2 = dynamic_cast<littnumber*>(&b);

    if (num1 != 0 && num2 != 0) {
        littnumber* res = (*(num1)-(num2));
        if (res->isPos() == false && res->isNull() == false ) {
            littEntiere* ret = new littEntiere(1);
            return *ret;
        }
        else {
            littEntiere* ret = new littEntiere(0);
            return *ret;
        }
    }
    else throw ComputerException("Format incompatible des arguments, nécessite deux nombres");
}

/******************** < : inferiorite *****************************/

litterale& opsup::traitement(litterale& a, litterale& b)
{

    littnumber* num1 = dynamic_cast<littnumber*>(&a);
    littnumber* num2 = dynamic_cast<littnumber*>(&b);

    if (num1 != 0 && num2 != 0) {
        littnumber* res = (*(num1)-(num2));
        if (res->isPos() && res->isNull() == false) {
            littEntiere* ret = new littEntiere(1);
            return *ret;
        }
        else {
            littEntiere* ret = new littEntiere(0);
            return *ret;
        }
    }
    else throw ComputerException("Format incompatible des argument, nécessite un nombre");
}

/************** IFT : Opérateur conditionnel If then ******************/

litterale& opIft::traitement(litterale& a, litterale& b)
{

    littEntiere* booleen = dynamic_cast<littEntiere*>(&a);
    littProgramme* prog = dynamic_cast<littProgramme*>(&b);


    if (booleen != 0 && prog != 0) {
        if(booleen->getValeur()==1){
            opeval* ope = new opeval();
            opdup* opee=new opdup();
            opee->traitement();
            litterale& a = ope->traitement(*prog);
            return a;
        }
        else throw ComputerException("La valeur est 0, on abandonne");
    }
    else throw ComputerException("Format incompatible des argument, nécessite un nombre et un programme");
}

/************* DUP : double la dernière littérale ***************/
void opdup::traitement(){
        Controleur& ctrl = Controleur::getInstance();
        Pile& pile = ctrl.getterPile();
        litterale& adup = pile.top();
        litterale& ret = adup;
        pile.push(ret);
        //return 0;
}
/********** EVAL : Evalue un programme *************************/

litterale& opeval::traitement(litterale& a)
{
    littProgramme* pg = dynamic_cast<littProgramme*>(&a);

    if (pg != 0) {
        QString final = pg->getStr();
        final = final.remove(0,1); //Retire 1 caractere , à partir du 0 eme caractere
        final = final.remove(final.length()-1,1);
        Controleur& ctrl = Controleur::getInstance();
        Pile& p = ctrl.getterPile();
        p.pop();
        ctrl.commande(final);
        QStringList prog;
        prog = final.split('[', QString::SkipEmptyParts);
        if (prog.length() == 1) {
            litterale& res = p.top();
            return res;
        }
        else {
            litterale& res = p.top();
            for(unsigned int i=1; i<prog.length();i++){
                p.pop();
            }
            return res;
        }
    }
    else throw ComputerException("Ce n'est pas un nombre !");
}
