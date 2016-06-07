#include "littcomplexe.h"

littcomplexe::littcomplexe(littcomplexe const& source)
{
    this->partIm = source.getPartRe();
    this->partRe = source.getPartIm();
}

litterale* littcomplexe::simplifier(){ //simplifie un complexe dans une littérale de sa partie réelle  si sa partie imaginaire est nulle
    if (this->getPartIm()==0){
        littEntiere* ent1 = dynamic_cast<littEntiere*>(this->getPartRe());
        littrat* rat1 = dynamic_cast<littrat*>(this->getPartRe());
        littReelle* ree1 = dynamic_cast<littReelle*>(this->getPartRe());
        if (ent1 != 0) {
            littEntiere* l = new littEntiere(ent1->getValeur());
            return l;
        }
        else if (rat1 != 0) {
            littrat* l = new littrat(rat1->getNum(),rat1->getDen());
            return l;
        }
        else if (ree1 != 0) {
            littReelle* l = new littReelle(ree1->getEntiere(), ree1->getDecimale());
            return l;
        }
    }
    else return this;
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
