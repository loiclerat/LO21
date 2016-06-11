#include "neg.h"

litterale& neg::traitement(litterale &a){

    littnumber* b = dynamic_cast<littnumber*>(&a);

    //littEntiere x(-1);
    if(b != 0)
    {// Si la litt�rale sur laquelle est le NEG est une litt�rale number alors on fait les calculs pour avoir l'oppos�
        littEntiere* ent1 = dynamic_cast<littEntiere*>(&a);
        littrat* rat1 = dynamic_cast<littrat*>(&a);
        littReelle* ree1 = dynamic_cast<littReelle*>(&a);
        littcomplexe* comp1 = dynamic_cast<littcomplexe*>(&a);

        if(ent1!=0){//si c'est un entier nouvelle litt�rale enti�re avec l'oppos� en valeur
            littEntiere* res= new littEntiere(-1*ent1->getValeur());
            return *res;
        }
        if(rat1!=0){//si c'est un rationnel nouvelle litt�rale rationnelle avec l'oppos� en valeur
            littrat* res= new littrat(-1*rat1->getNum());
            return *res;
        }
        if(ree1!=0){//si c'est un entier nouvelle litt�rale r�elle avec l'oppos� de la partie enti�re
            littReelle* res= new littReelle(-1*ree1->getEntiere(),-1*ree1->getDecimale());
            return *res;
        }
        if(comp1!=0){//si c'est un entier nouvelle litt�rale enti�re avec l'oppos� en valeur
            littEntiere x(-1);
            littNumerique * temp1 = x*(comp1->getPartRe()); //construction de cette nouvelle littNumerique dans la surcharge d'operateur * de littEntiere
            qDebug()<<temp1->affichage();
            littNumerique * temp2 = x*(comp1->getPartIm());
            qDebug()<<temp2->affichage();
            littcomplexe* res= new littcomplexe(temp1,temp2);
            return *res;
        }

    }else {
        throw ComputerException("Ce n'est pas un nombre !");
    }
}
