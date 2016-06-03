
#include"littreelle.h"

littReelle* littReelle::operator+(littReelle* b){
    int ent;
    float val, dec;
    val=b->getValeur()+this->getValeur();// addition des valeurs réelles
    ent=static_cast<int>(val); // partie entiere de la valeur réelle de la soustraction
    dec=val-ent;// partie décimale de la valeur réelle de l'addition
    littReelle* res=new littReelle(ent,dec);
    return res; // float + float = float
}

littReelle& littReelle::operator+(littReelle& b){
    int ent;
    float val, dec;
    val=b.getValeur()+this->getValeur();// addition des valeurs réelles
    ent=static_cast<int>(val); // partie entiere de la valeur réelle de la soustraction
    dec=val-ent;// partie décimale de la valeur réelle de l'addition
    littReelle* res=new littReelle(ent,dec);
    return (*res); // float + float = float
}

littNumerique* littReelle::operator+(littNumerique* a)
{

        littEntiere* ent1 = dynamic_cast<littEntiere*>(a);

        littrat* rat1 = dynamic_cast<littrat*>(a);

        littReelle* ree1 = dynamic_cast<littReelle*>(a);

        if(ent1!=nullptr)
        {
            float c = 0.0 + ent1->getValeur();
            c = c + this->getValeur();
            littReelle* res = new littReelle(c);
            return res;

        }else
            if(rat1!=nullptr){
                float c = rat1->getNum()/rat1->getDen();
                c = c + this->getValeur();
                littReelle* res = new littReelle(c);
                return res;

            }else
                if(ree1!=nullptr){
                    littReelle* res(*this+ree1);
                    return res;
            }
    }

/*littReelle* littReelle::operator+(littEntiere* a){
    int ent;
    float dec;
    ent=a->getValeur()+this->getEntiere();
    dec=this->getDecimale();// partie décimale de la valeur réelle de l'addition
    littReelle* res=new littReelle(ent,dec);
    return res; // float + float = float
}

littReelle* littReelle::operator+(littrat* a){
    int ent;
    float val, dec;
    float rationnelle = a->getNum()/a->getDen();
    val=rationnelle+this->getValeur();// addition des valeurs réelles
    ent=static_cast<int>(val); // partie entiere de la valeur réelle de la soustraction
    dec=val-ent;// partie décimale de la valeur réelle de l'addition
    littReelle* res=new littReelle(ent,dec);
    return res; // float + float = float
}
*/

littReelle& littReelle::operator -(littReelle& b){
    int ent;
    float val, dec;
    val=this->valeur-b.valeur;// soustraction des valeurs réelles
    ent=static_cast<int>(val); // partie entiere de la valeur réelle de la soustraction
    dec=val-ent;// partie décimale de la valeur réelle de la soustraction
    littReelle* res=new littReelle(this->valeur-b.valeur);
    return (*res); // reel - reel = reel, ou pas mais le constructeur simplifiera
}

littReelle& littReelle::operator*(littReelle& b){
    int ent;
    float val, dec;
    val=this->valeur*b.valeur; //multiplication des valeurs réelles
    ent=static_cast<int>(val);
    dec=val-ent;
    littReelle* res=new littReelle(ent,dec);
    return (*res); // reel * reel = reel, ou pas mais le constructeur simplifiera
}


void littReelle::simplifier(){
    if(this->decimale==0){
        throw Exception("entier");
    }
}
