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

littNumerique* littrat::operator+(littNumerique* a)
{

        littEntiere* ent1 = dynamic_cast<littEntiere*>(a);

        littrat* rat1 = dynamic_cast<littrat*>(a);

        littReelle* ree1 = dynamic_cast<littReelle*>(a);

        if(ent1!=nullptr)
        {
            littrat* res = new littrat(this->getNum()+ent1->getValeur(),this->getDen());
            return res;

        }else if(rat1!=nullptr){
            littrat* res = new littrat(0,0);
            res=*this+rat1;
            return res;
        }else if(ree1!=nullptr){
            float val = this->getNum()/this->getDen();
            littReelle* a = new littReelle(val);
            littReelle* res(*a+ree1);
            return res;
        }
    }

littrat* littrat::operator+(littrat* b){
        littrat* res=new littrat(this->getNum()*b->den+this->getDen()*b->num,this->getDen()*b->den);
        res->simplifier();
        return (res);
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
