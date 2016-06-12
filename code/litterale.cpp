#include "litterale.h"

littnumber* littnumber::operator-(littnumber* a){
    littcomplexe* comp = dynamic_cast<littcomplexe*>(this);
    littNumerique* num = dynamic_cast<littNumerique*>(this);

    if(comp != 0){
        littnumber* res = *(comp)-a;
        return res;
    }
    else
        if(num != 0){
            littnumber* resf = *(num)-a;
            return resf;
        }
    return 0;
}

/********************************************************************************/


littnumber* littNumerique::operator-(littnumber* a){
    littEntiere* ent = dynamic_cast<littEntiere*>(this);
    littrat* rat = dynamic_cast<littrat*>(this);
    littReelle* ree = dynamic_cast<littReelle*>(this);

    if(ent != 0){
        littnumber* res = *(ent)-a;
        return res;
    }
    else
        if(rat != 0){
            littnumber* resf = *(rat)-a;
            return resf;
        }
    else
            if(ree != 0){
                littnumber* resff = *(ree)-a;
                return resff;
            }
            else{
                throw ComputerException("operation impossible");
    }
}

/****************************************************************************/


littnumber* littEntiere::operator+(littnumber* a)
{
    littNumerique* ltb = dynamic_cast<littNumerique*>(a);
    littcomplexe* ltc = dynamic_cast<littcomplexe*>(a);

    if (ltb != 0) {
        littNumerique* res = *(this) + ltb;
        return res;
    }
    else {
        littcomplexe* res2 = new littcomplexe((*this) + ltc->getPartRe(), ltc->getPartIm());
        return res2;
    }
}

littNumerique* littEntiere::operator+(littNumerique* a)
{
    littReelle* ree1 = dynamic_cast<littReelle*>(a);
    littEntiere* ent1 = dynamic_cast<littEntiere*>(a);
    littrat* rat1 = dynamic_cast<littrat*>(a);

    if (ent1 != 0) {
        littEntiere* r = new littEntiere(valeur + ent1->getValeur());
        return r;
    }
    else if (rat1 != 0) {
        littrat* r = new littrat(this->valeur + rat1->getNum(), rat1->getDen());
        return r;
    }
    else if (ree1 != 0) {
        littReelle* r = new littReelle(this->getValeur() + ree1->getEntiere(), ree1->getDecimale());
        return r;
    }
    else {
        return 0;
    }
}

littnumber* littEntiere::operator-(littnumber* a)
{
    littNumerique* ltb = dynamic_cast<littNumerique*>(a);
    littcomplexe* ltc = dynamic_cast<littcomplexe*>(a);

    if (ltb != 0) {
        littNumerique* res = *(this) - ltb;
        return res;
    }
    else {
        littcomplexe* res2 = new littcomplexe((*this) - ltc->getPartRe(), ltc->getPartIm());
        return res2;
    }
}

littNumerique* littEntiere::operator-(littNumerique* a)
{

    littEntiere* ent1 = dynamic_cast<littEntiere*>(a);

    littrat* rat1 = dynamic_cast<littrat*>(a);

    littReelle* ree1 = dynamic_cast<littReelle*>(a);

    if (ent1 != 0) {
        littEntiere* r = new littEntiere(valeur - ent1->getValeur());
        return r;
    }
    else if (rat1 != 0) {
        littrat* r = new littrat(this->valeur - rat1->getNum(), rat1->getDen());
        return r;
    }
    else if (ree1 != 0) {
        littReelle* r = new littReelle(this->getValeur() - ree1->getEntiere(), 0.0 - ree1->getDecimale());
        return r;
    }
    else {
        return 0;
    }
}

littnumber* littEntiere::operator*(littnumber* a)
{

    if (this->getValeur() == 0) {
        littEntiere* res = new littEntiere(0);
        return res;
    }
    littNumerique* ltb = dynamic_cast<littNumerique*>(a);

    littcomplexe* ltc = dynamic_cast<littcomplexe*>(a);

    if (ltb != 0) {
        littNumerique* res = *(this) * ltb;
        return res;
    }
    else {
        littEntiere* un = new littEntiere(this->getValeur());
        littEntiere* deux = new littEntiere(this->getValeur());
        littcomplexe* res2 = new littcomplexe(*un * ltc->getPartRe(), *deux * ltc->getPartIm());
        return res2;
    }
}

littNumerique* littEntiere::operator*(littNumerique* a)
{

    if (this->getValeur() == 0) { //si un des deux membres est nul =0
        littEntiere* res = new littEntiere(0);
        return res;
    }
    littEntiere* ent1 = dynamic_cast<littEntiere*>(a);

    littrat* rat1 = dynamic_cast<littrat*>(a);

    littReelle* ree1 = dynamic_cast<littReelle*>(a);

    if (ent1 != 0) {
        littEntiere* res= new littEntiere(valeur * ent1->getValeur());
        return res;
    }
    else if (rat1 != 0) {
        littrat* r = new littrat(this->valeur * rat1->getNum(), rat1->getDen());
        return r;
    }
    else if (ree1 != 0) {
        littReelle* r = new littReelle(this->getValeur() * ree1->getEntiere(), this->getValeur() * ree1->getDecimale());
        return r;
    }
    else {
        return 0;
    }
}

littnumber* littEntiere::operator/(littnumber* a)
{
    if (this->getValeur() == 0) {
        littEntiere* res = new littEntiere(0);
        return res;
    }
    littNumerique* ltb = dynamic_cast<littNumerique*>(a);

    littcomplexe* ltc = dynamic_cast<littcomplexe*>(a);

    if (ltb != 0) {
        littNumerique* res = *(this) / ltb;
        return res;
    }
    else {
        littcomplexe* res2 = new littcomplexe((*this) / ltc->getPartRe(), (*this) / ltc->getPartIm());
        return res2;
    }
}

littNumerique* littEntiere::operator/(littNumerique* a)
{

    if (this->getValeur() == 0) {
        littEntiere* res = new littEntiere(0);
        return res;
    }

    littEntiere* ent1 = dynamic_cast<littEntiere*>(a);
    littrat* rat1 = dynamic_cast<littrat*>(a);
    littReelle* ree1 = dynamic_cast<littReelle*>(a);

    if (ent1 != 0) {
        littrat* r = new littrat(valeur, ent1->getValeur());
        return r;
    }
    else if (rat1 != 0) {
        littrat* r = new littrat(this->valeur * rat1->getDen(), rat1->getNum());
        return r;
    }
    else if (ree1 != 0) {
        littReelle* r = new littReelle((valeur / ree1->getValeur()));
        return r;
    }
   /* else {
        return 0;
    }*/
}

/*******************************************************************************/



litterale* littrat::simplifier(){
    if (den==0) return 0;
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
        delete this;
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

/*********************************************************************************************************/

littReelle* littReelle::operator+(littReelle* b)
{
    int ent;
    float val, dec;
    val = b->getValeur() + this->getValeur(); // addition des valeurs réelles
    ent = static_cast<int>(val); // partie entiere de la valeur réelle de la soustraction
    dec = val - ent; // partie décimale de la valeur réelle de l'addition
    littReelle* res = new littReelle(ent, dec);
    return res; // float + float = float
}


littReelle* littReelle::operator-(littReelle* b)
{
    int ent;
    float val, dec;
    val = this->valeur - b->valeur; // soustraction des valeurs réelles
    ent = static_cast<int>(val); // partie entiere de la valeur réelle de la soustraction
    dec = val - ent; // partie décimale de la valeur réelle de la soustraction
    littReelle* res = new littReelle(this->valeur - b->valeur);
    return res; // reel - reel = reel, ou pas mais le constructeur simplifiera
}

littnumber* littReelle::operator+(littnumber* a)
{
    littNumerique* ltb = dynamic_cast<littNumerique*>(a);
    littcomplexe* ltc = dynamic_cast<littcomplexe*>(a);

    if (ltb != 0) {
        littNumerique* res = *(this) + ltb;
        return res;
    }
    else {
        littcomplexe* res2 = new littcomplexe((*this) + ltc->getPartRe(), ltc->getPartIm());
        return res2;
    }
}

littNumerique* littReelle::operator+(littNumerique* a)
{
    littEntiere* ent1 = dynamic_cast<littEntiere*>(a);
    littrat* rat1 = dynamic_cast<littrat*>(a);
    littReelle* ree1 = dynamic_cast<littReelle*>(a);

    if (ent1 != 0) {
        float c = 0.0 + ent1->getValeur();
        c = c + this->getValeur();
        littReelle* res = new littReelle(c);
        return res;
    }
    else if (rat1 != 0) {
        float c = rat1->getNum() / rat1->getDen();
        c = c + this->getValeur();
        littReelle* res = new littReelle(c);
        return res;
    }
    else if (ree1 != 0) {
        littReelle* res(*this + ree1);
        return res;
    }
    else {
        return 0;
    }
}

littnumber* littReelle::operator-(littnumber* a)
{
    littNumerique* ltb = dynamic_cast<littNumerique*>(a);
    littcomplexe* ltc = dynamic_cast<littcomplexe*>(a);

    if (ltb != 0) {
        littNumerique* res = *(this) - ltb;
        return res;
    }
    else {
        littcomplexe* res2 = new littcomplexe((*this) - ltc->getPartRe(), ltc->getPartIm());
        return res2;
    }
}

littNumerique* littReelle::operator-(littNumerique* a)
{
    littEntiere* ent1 = dynamic_cast<littEntiere*>(a);
    littrat* rat1 = dynamic_cast<littrat*>(a);
    littReelle* ree1 = dynamic_cast<littReelle*>(a);

    if (ent1 != 0) {
        float c = 0.0 + ent1->getValeur();
        c = this->getValeur() - c;
        littReelle* res = new littReelle(c);
        return res;
    }
    else if (rat1 != 0) {
        float c = rat1->getNum() / rat1->getDen();
        c = this->getValeur() - c;
        littReelle* res = new littReelle(c);
        return res;
    }
    else if (ree1 != 0) {
        littReelle* res(*this - ree1);
        return res;
    }
    else {
        return 0;
    }
}

littnumber* littReelle::operator*(littnumber* a)
{

    if (this->getValeur() == 0.0) {
        littReelle* res = new littReelle(0);
        return res;
    }

    littNumerique* ltb = dynamic_cast<littNumerique*>(a);
    littcomplexe* ltc = dynamic_cast<littcomplexe*>(a);

    if (ltb != 0) {
        littNumerique* res = *(this) * ltb;
        return res;
    }
    else {
        littcomplexe* res2 = new littcomplexe((*this) * ltc->getPartRe(), (*this) * ltc->getPartIm());
        return res2;
    }
}

littNumerique* littReelle::operator*(littNumerique* a)
{
    if (this->getValeur() == 0.0) {
        littReelle* res = new littReelle(0);
        return res;
    }

    littEntiere* ent1 = dynamic_cast<littEntiere*>(a);

    littrat* rat1 = dynamic_cast<littrat*>(a);

    littReelle* ree1 = dynamic_cast<littReelle*>(a);

    if (ent1 != 0) {
        float c = 0.0 + ent1->getValeur();
        c = this->getValeur() * c;
        littReelle* res = new littReelle(c);
        return res;
    }
    else if (rat1 != 0) {
        float c = rat1->getNum() / rat1->getDen();
        c = this->getValeur() * c;
        littReelle* res = new littReelle(c);
        return res;
    }
    else if (ree1 != 0) {
        littReelle* res(*this * ree1);
        return res;
    }
    else {
        return 0;
    }
}


littReelle* littReelle::operator*(littReelle* b)
{
    int ent;
    float val, dec;
    val = this->valeur * b->valeur; //multiplication des valeurs réelles
    ent = static_cast<int>(val);
    dec = val - ent;
    littReelle* res = new littReelle(ent, dec);
    return res; // reel * reel = reel, ou pas mais le constructeur simplifiera
}

littReelle* littReelle::operator/(littReelle* b)
{
    int ent;
    float val, dec;
    val = this->valeur / b->valeur;
    ent = static_cast<int>(val);
    dec = val - ent;
    littReelle* res = new littReelle(ent, dec);
    return res;
}

littnumber* littReelle::operator/(littnumber* a)
{
    if (this->isNull()) {
        littEntiere* res = new littEntiere(0);
        return res;
    }
    littNumerique* ltb = dynamic_cast<littNumerique*>(a);

    littcomplexe* ltc = dynamic_cast<littcomplexe*>(a);

    if (ltb != 0) {
        littNumerique* res = *(this) / ltb;
        return res;
    }
    else {
        littcomplexe* res2 = new littcomplexe((*this) / ltc->getPartRe(), (*this) / ltc->getPartIm());
        return res2;
    }
}

littNumerique* littReelle::operator/(littNumerique* a)
{
    if (this->isNull()) {
        littEntiere* res = new littEntiere(0);
        return res;
    }
    littEntiere* ent1 = dynamic_cast<littEntiere*>(a);
    littrat* rat1 = dynamic_cast<littrat*>(a);
    littReelle* ree1 = dynamic_cast<littReelle*>(a);

    if (ent1 != 0) {
        if (ent1->isNull()){
            littrat* res = new littrat(ent1->getValeur(), 0);
            return res;
        }
        float c = 0.0 + ent1->getValeur();
        c = this->getValeur() / c;
        littReelle* res = new littReelle(c);
        return res;
    }
    else if (rat1 != 0) {
        float c = rat1->getNum() / rat1->getDen();
        c = this->getValeur() / c;
        littReelle* res = new littReelle(c);
        return res;
    }
    else if (ree1 != 0) {
        littReelle* res(*this / ree1);
        return res;
    }
    else {
        return 0;
    }
}

litterale *littReelle::simplifier()
{
    if (this->decimale == 0) {
        littEntiere* l = new littEntiere(this->getEntiere());
        delete this;
        return l;
    }
    else return this;
}

/***************************************************************************************************/


littcomplexe::littcomplexe(littcomplexe const& source)
{
    this->partIm = source.getPartRe();
    this->partRe = source.getPartIm();
}


litterale* littcomplexe::simplifier(){ //simplifie un complexe dans une litt�rale de sa partie r�elle si sa partie imaginaire est nulle


    if (this->getPartIm()->isNull()){
        littEntiere* ent1 = dynamic_cast<littEntiere*>(this->getPartRe());
        littrat* rat1 = dynamic_cast<littrat*>(this->getPartRe());
        littReelle* ree1 = dynamic_cast<littReelle*>(this->getPartRe());
        if (ent1 != 0) {
            littEntiere* l = new littEntiere(ent1->getValeur());
            return l;
        }
        else if (rat1 != 0) {
            littrat* l = new littrat(rat1->getNum(),rat1->getDen());
            return l->simplifier();
        }
        else if (ree1 != 0) {
            littReelle* l = new littReelle(ree1->getEntiere(), ree1->getDecimale());
            return l->simplifier();
        }
    }
    else{
        littcomplexe* l = new littcomplexe(dynamic_cast<littNumerique*>(this->getPartRe()->simplifier()), dynamic_cast<littNumerique*>(this->getPartIm()->simplifier()));
        if (l->getPartIm() == 0 || l->getPartRe() == 0){
            return 0;
        }
        return l;
    }

    return this;
}

littnumber* littcomplexe::operator+(littnumber* a)
{

    littEntiere* ent1 = dynamic_cast<littEntiere*>(a);

    littrat* rat1 = dynamic_cast<littrat*>(a);

    littReelle* ree1 = dynamic_cast<littReelle*>(a);

    if (ent1 != 0) {
        littNumerique* res1 = *(this->getPartRe()) + ent1;
        littcomplexe* r = new littcomplexe(res1, this->getPartIm());
        return r;
    }
    else if (rat1 != 0) {
        littcomplexe* r = new littcomplexe(*(this->getPartRe()) + rat1, this->getPartIm());
        return r;
    }
    else if (ree1 != 0) {
        littcomplexe* r = new littcomplexe(*(this->getPartRe()) + ree1, this->getPartIm());
        return r;
    }
    else {
        return 0;
    }
}

littnumber* littcomplexe::operator-(littnumber* a)
{
    littEntiere* ent1 = dynamic_cast<littEntiere*>(a);

    littrat* rat1 = dynamic_cast<littrat*>(a);

    littReelle* ree1 = dynamic_cast<littReelle*>(a);

    if (ent1 != 0) {
        littcomplexe* r = new littcomplexe(*(this->getPartRe()) - ent1, this->getPartIm());
        return r;
    }
    else if (rat1 != 0) {
        littcomplexe* r = new littcomplexe(*(this->getPartRe()) - rat1, this->getPartIm());
        return r;
    }
    else if (ree1 != 0) {
        littcomplexe* r = new littcomplexe(*(this->getPartRe()) - ree1, this->getPartIm());
        return r;
    }
    else {
        return 0;
    }
}

littnumber* littcomplexe::operator*(littnumber* a)
{
    littEntiere* ent1 = dynamic_cast<littEntiere*>(a);

    littrat* rat1 = dynamic_cast<littrat*>(a);

    littReelle* ree1 = dynamic_cast<littReelle*>(a);

    if (ent1 != 0) {
        littcomplexe* r = new littcomplexe(*(this->getPartRe()) * ent1, *(this->getPartIm()) * ent1);
        return r;
    }
    else if (rat1 != 0) {
        littcomplexe* r = new littcomplexe(*(this->getPartRe()) * rat1, *(this->getPartIm()) * rat1);
        return r;
    }
    else if (ree1 != 0) {
        littcomplexe* r = new littcomplexe(*(this->getPartRe()) * ree1, *(this->getPartIm()) * ree1);
        return r;
    }
    else {
        return 0;
    }
}

littnumber* littcomplexe::operator/(littnumber* a)
{
    littEntiere* ent1 = dynamic_cast<littEntiere*>(a);

    littrat* rat1 = dynamic_cast<littrat*>(a);

    littReelle* ree1 = dynamic_cast<littReelle*>(a);

    if (ent1 != 0) {
        littcomplexe* r = new littcomplexe(*(this->getPartRe()) / ent1, *(this->getPartIm()) / ent1);
        return r;
    }
    else if (rat1 != 0) {
        littcomplexe* r = new littcomplexe(*(this->getPartRe()) / rat1, *(this->getPartIm()) / rat1);
        return r;
    }
    else if (ree1 != 0) {
        littcomplexe* r = new littcomplexe(*(this->getPartRe()) / ree1, *(this->getPartIm()) / ree1);
        return r;
    }
    else {
        return 0;
    }
}

/*******************************************************************************************************/


