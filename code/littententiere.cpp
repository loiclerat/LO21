
#include"littentiere.h"


littEntiere& littEntiere::operator+(littEntiere& b){
        littEntiere* res=new littEntiere(this->valeur+b.valeur);
        return (*res); // int + int = int
}


littEntiere& littEntiere::operator -(littEntiere& b){
    littEntiere* res=new littEntiere(this->valeur-b.valeur);
    return (*res); // int - int = int
}

/*
littEntiere& operator*(littEntiere& b){
    littEntiere*
}*/

