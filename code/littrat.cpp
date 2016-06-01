#include "littrat.h"


void littrat::simplifier(){
    cout<<"Simplification de la littérale rationnelle"<<"\n";
    if (den==0) return;
    int a=num, b=den;
    if (a<0) a=-a; if (b<0) b=-b;
    while(a!=b){ if (a>b) a=a-b; else b=b-a; }
    num/=a; den/=a;
    if (den<0) {
        den=-den;
        num=-num;
    }
}

/*littrat* littrat::operator+(littrat* a, littrat* b){
    littrat* res=new littrat(a->getNum()*b->getDen()+a->getDen()*b->getNum(),a->getDen()*b->getDen());
    res->simplifier();
    return res;
}*/

littrat& littrat::operator+(littrat& b){
        littrat* res=new littrat(this->getNum()*b.den+this->getDen()*b.num,this->getDen()*b.den);
        res->simplifier();
        return (*res);
}


littrat& littrat::operator-(littrat& b){
    littrat* res=new littrat(this->getNum()*b.den-this->getDen()*b.num,this->getDen()*b.den);
    res->simplifier();
    return (*res);
}

littrat& littrat::operator*(littrat& b){
    littrat* res=new littrat(this->getNum()*b.num,this->getDen()*b.den);
    res->simplifier();
    return (*res);
}

littrat& littrat::operator/(littrat& b){
    littrat* res=new littrat(this->getNum()*b.den,this->getDen()*b.num);
    res->simplifier();
    return (*res);
}
