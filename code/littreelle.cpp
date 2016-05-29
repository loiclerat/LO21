
#include"littreelle.h"

littReelle& littReelle::operator+(littReelle& b){
    int ent;
    float val, dec;
    val=b.getValeur()+this->getValeur();// addition des valeur réelles

    cout<<" \n COUCOU VAL "<<val<<"\n";
    ent=b.getEntiere()+this->getEntiere(); //addition des parties entieres
    cout<<"COUCOU ENT "<<ent<<"\n";
    dec=val-ent;

    cout<<"COUCOU DEC "<<dec<<"\n";
    if(dec>=1){
        dec-=1; //on enlève la retenue
        ent+=1; // on l'ajoute à la partie entière
    }
    cout<<"RECOUCOU DEC "<<dec<<"\n";

    littReelle* res=new littReelle(ent,dec);
    return (*res); // float + float = float
}


littReelle& littReelle::operator -(littReelle& b){
    int ent, dec;

    dec=;
    littReelle* res=new littReelle(this->valeur-b.valeur);
    return (*res); // reel - reel = reel, ou pas mais le constructeur simplifiera
}


void simplifier(){

}

/*littReelle& operator*(littReelle& b){
    littReelle*
}*/

