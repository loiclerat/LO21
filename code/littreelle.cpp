
#include"littreelle.h"

littReelle& littReelle::operator+(littReelle& b){
    int ent;
    float val, dec;
    val=b.getValeur()+this->getValeur();// addition des valeurs r�elles
    ent=static_cast<int>(val); // partie entiere de la valeur r�elle de la soustraction
    dec=val-ent;// partie d�cimale de la valeur r�elle de l'addition
    littReelle* res=new littReelle(ent,dec);
    return (*res); // float + float = float
}


littReelle& littReelle::operator -(littReelle& b){
    int ent;
    float val, dec;
    val=this->valeur-b.valeur;// soustraction des valeurs r�elles
    ent=static_cast<int>(val); // partie entiere de la valeur r�elle de la soustraction
    dec=val-ent;// partie d�cimale de la valeur r�elle de la soustraction
    littReelle* res=new littReelle(this->valeur-b.valeur);
    return (*res); // reel - reel = reel, ou pas mais le constructeur simplifiera
}

littReelle& littReelle::operator*(littReelle& b){
    int ent;
    float val, dec;
    val=this->valeur*b.valeur; //multiplication des valeurs r�elles
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
