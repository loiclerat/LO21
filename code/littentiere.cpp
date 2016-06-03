
#include"littentiere.h"


littEntiere& littEntiere::operator+(littEntiere& b){
        littEntiere* res=new littEntiere(this->valeur+b.valeur);
        return (*res); // int + int = int
}


littEntiere& littEntiere::operator -(littEntiere& b){
    littEntiere* res=new littEntiere(this->valeur-b.valeur);
    return (*res); // int - int = int
}


littEntiere&  littEntiere::operator*(littEntiere& b){
    littEntiere* res=new littEntiere(this->valeur*b.valeur);
    return (*res); //int*int = int
}
/*
littEntiere&  littEntiere::operator/(littEntiere& b){
    littEntiere* res=new littEntiere(this->valeur/b.valeur);
    return (*res); //int/int = rationnel ou entiere
}*/

/*littEntiere* littEntiere::operator+(littEntiere* a){
        littEntiere* res=new littEntiere(this->getValeur()+a->getValeur());
        res->simplifier();
        return (res);
}*/



littNumerique* littEntiere::operator+(littNumerique* a)
{

        littReelle* ree1 = dynamic_cast<littReelle*>(a);

        littEntiere* ent1 = dynamic_cast<littEntiere*>(a);
        littrat* rat1 = dynamic_cast<littrat*>(a);
        if(ent1!=nullptr)
        {
            valeur=valeur+ent1->getValeur();
            return this;
        }else if(rat1!=nullptr){
            littrat* a = new littrat(this->valeur+rat1->getNum(),rat1->getDen());
            return a;
        }else if(ree1!=nullptr){
            littReelle* a = new littReelle(this->getValeur()+ree1->getEntiere(),ree1->getDecimale());
            return a;
        }
}

