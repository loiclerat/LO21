#include "littrat.h"


litterale* littrat::simplifier(){
    if (den==0) throw ComputerException("Denominateur = 0");
    int a=num, b=den;
    if (a<0) a=-a; if (b<0) b=-b;
    while(a!=b){ if (a>b) a=a-b; else b=b-a; }
    num/=a; den/=a;
    if (den<0) {
        den=-den;
        num=-num;
    }
    if (den==1){ //retourner un entier
        littEntiere* l= new littEntiere(this->getNum());
        return l;
    }
    else return this;
}

littnumber* littrat::operator+(littnumber* a){
    littNumerique* ltb = dynamic_cast<littNumerique*>(a);

    littcomplexe* ltc = dynamic_cast<littcomplexe*>(a);

    if(ltb!=0){
        littNumerique* res = *(this)+ltb;
        return res;
    }
    else {
        littcomplexe* res2 = new littcomplexe(*this+ltc->getPartRe(),ltc->getPartIm());
        return res2;
    }
}

littNumerique* littrat::operator+(littNumerique* a)
{

        littEntiere* ent1 = dynamic_cast<littEntiere*>(a);

        littrat* rat1 = dynamic_cast<littrat*>(a);

        littReelle* ree1 = dynamic_cast<littReelle*>(a);

        if(ent1!=0)
        {
            littrat* res = new littrat(this->getNum()+ent1->getValeur(),this->getDen());
            return res;

        }else if(rat1!=0){
            littrat* res = new littrat(0,0);
            res=*this+rat1;
            return res;
        }else if(ree1!=0){
            float val = this->getNum()/this->getDen();
            littReelle* a = new littReelle(val);
            littReelle* res(*a+ree1);
            return res;
        }
        else {
            return 0;
        }
}

littnumber* littrat::operator-(littnumber* a){
    littNumerique* ltb = dynamic_cast<littNumerique*>(a);

    littcomplexe* ltc = dynamic_cast<littcomplexe*>(a);

    if(ltb!=0){
        littNumerique* res = *(this)-ltb;
        return res;
    }
    else
    if (ltc!=0){
        littcomplexe* res2 = new littcomplexe((*this)-ltc->getPartRe(),ltc->getPartIm());
        return res2;
    }
    else {
        return 0;
    }
}

littNumerique* littrat::operator-(littNumerique* a)
{

        littEntiere* ent1 = dynamic_cast<littEntiere*>(a);

        littrat* rat1 = dynamic_cast<littrat*>(a);

        littReelle* ree1 = dynamic_cast<littReelle*>(a);

        if(ent1!=0)
        {
            littrat* res = new littrat(this->getNum()-ent1->getValeur(),this->getDen());
            return res;

        }else if(rat1!=0){
            littrat* res = new littrat(0,0);
            res=*this-rat1;
            return res;
        }else if(ree1!=0){
            float val = this->getNum()/this->getDen();
            littReelle* a = new littReelle(val);
            littReelle* res(*a-ree1);
            return res;
        }
        else {
            return 0;
        }
}


littnumber* littrat::operator*(littnumber* a){


    if(this->getNum()==0){
        littrat* res=new littrat(0);
        return res;
    }

    littNumerique* ltb = dynamic_cast<littNumerique*>(a);

    littcomplexe* ltc = dynamic_cast<littcomplexe*>(a);

    if(ltb!=0){
        littNumerique* res = *(this)*ltb;
        return res;
    }
    else {
        littcomplexe* res2 = new littcomplexe((*this)*ltc->getPartRe(),(*this)*ltc->getPartIm());
        return res2;
    }
}

littNumerique* littrat::operator*(littNumerique* a)
{

    if(this->getNum()==0){
        littrat* res=new littrat(0);
        return res;
    }
    littEntiere* ent1 = dynamic_cast<littEntiere*>(a);

    littrat* rat1 = dynamic_cast<littrat*>(a);

    littReelle* ree1 = dynamic_cast<littReelle*>(a);

    if(ent1!=0)
    {
        littrat* res = new littrat(this->getNum()*ent1->getValeur(),this->getDen());
        return res;

    }else if(rat1!=0){
        littrat* res = new littrat(0,0);
        res=*this*rat1;
        if(res->getDen()==0) throw ComputerException("Denominateur nul");
        else{
            return res;
        }
    }else if(ree1!=0){
        float val = this->getNum()/this->getDen();
        littReelle* a = new littReelle(val);
        littReelle* res(*a*ree1);
        return res;
    }
    else {
        return 0;
    }
}
littnumber* littrat::operator/(littnumber* a){
    if(this->getNum()==0){
        littrat* res=new littrat(0);
        return res;
    }
    littNumerique* ltb = dynamic_cast<littNumerique*>(a);

    littcomplexe* ltc = dynamic_cast<littcomplexe*>(a);

    if(ltb!=0){
        littNumerique* res = *(this)/ltb;
        return res;
    }
    else {
        littcomplexe* res2 = new littcomplexe((*this)/ltc->getPartRe(),(*this)/ltc->getPartIm());
        return res2;
    }
}

littNumerique* littrat::operator/(littNumerique* a)
{

    if(this->getNum()==0){
        littrat* res=new littrat(0);
        return res;
    }
    littEntiere* ent1 = dynamic_cast<littEntiere*>(a);

    littrat* rat1 = dynamic_cast<littrat*>(a);

    littReelle* ree1 = dynamic_cast<littReelle*>(a);

    if(ent1!=0)
    {
        littrat* res = new littrat(this->getNum(),this->getDen()*ent1->getValeur());
        return res;

    }else if(rat1!=0){
        littrat* res = new littrat(0,0);
        res=*this/rat1;
        return res;
    }else if(ree1!=0){
        float val = this->getNum()/this->getDen();
        littReelle* a = new littReelle(val);
        littReelle* res(*a/ree1);
        return res;
    }
    else {
        return 0;
    }
}


littrat* littrat::operator+(littrat* b){
        littrat* res=new littrat(this->getNum()*b->den+this->getDen()*b->num,this->getDen()*b->den);
        res->simplifier();
        return (res);
}


littrat* littrat::operator-(littrat* b){
        littrat* res=new littrat(this->getNum()*b->den-this->getDen()*b->num,this->getDen()*b->den);
        res->simplifier();
        return (res);
}
littrat* littrat::operator*(littrat* b){
    littrat* res=new littrat(this->getNum()*b->num,this->getDen()*b->den);
    res->simplifier();
    return res;
}

littrat* littrat::operator/(littrat* b){
    littrat* res=new littrat(this->getNum()*b->den,this->getDen()*b->num);
    res->simplifier();
    return res;
}
