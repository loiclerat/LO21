
#include"littreelle.h"

littReelle& littReelle::operator+(littReelle& b){
    int ent;
    float val, dec;
    val=b.getValeur()+this->getValeur();// addition des valeurs réelles
    ent=b.getEntiere()+this->getEntiere(); //addition des parties entieres
    dec=val-ent;
    if(dec>=1){
        dec-=1; //on enlève la retenue de la partie décimale
        ent+=1; // on l'ajoute à la partie entière
    }

    littReelle* res=new littReelle(ent,dec);
    return (*res); // float + float = float
}


littReelle& littReelle::operator -(littReelle& b){
    int ent;
    float val, dec;
    val=this->valeur-b.valeur;// soustraction des valeurs réelles
    ent=this->entiere-b.entiere;//soustraction des parties entieres
    dec=this->decimale-b.decimale;
    if(dec<=-1){
        dec+=1; //on enlève la retenue de la partie décimale
        ent-=1; // on l'ajoute à la partie entière
    }
    littReelle* res=new littReelle(this->valeur-b.valeur);
    return (*res); // reel - reel = reel, ou pas mais le constructeur simplifiera
}
/*

void simplifier(){

}
*/
/*littReelle& operator*(littReelle& b){
    littReelle*
}*/

