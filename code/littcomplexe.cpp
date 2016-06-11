#include "littcomplexe.h"

littcomplexe::littcomplexe(littcomplexe const& source)
{
    this->partIm = source.getPartRe();
    this->partRe = source.getPartIm();
}


litterale* littcomplexe::simplifier(){ //simplifie un complexe dans une littérale de sa partie réelle si sa partie imaginaire est nulle


    if (this->getPartIm()->isNull()){
        littEntiere* ent1 = dynamic_cast<littEntiere*>(this->getPartRe());
        littrat* rat1 = dynamic_cast<littrat*>(this->getPartRe());
        littReelle* ree1 = dynamic_cast<littReelle*>(this->getPartRe());
        if (ent1 != 0) {
            littEntiere* l = new littEntiere(ent1->getValeur());
            delete rat1;
            delete ree1;
            return l;
        }
        else if (rat1 != 0) {
            littrat* l = new littrat(rat1->getNum(),rat1->getDen());
            delete ent1;
            delete ree1;
            return l->simplifier();
        }
        else if (ree1 != 0) {
            littReelle* l = new littReelle(ree1->getEntiere(), ree1->getDecimale());
            delete rat1;
            delete ent1;
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
        delete rat1;
        delete ree1;
        return r;
    }
    else if (rat1 != 0) {
        littcomplexe* r = new littcomplexe(*(this->getPartRe()) + rat1, this->getPartIm());
        delete ent1;
        delete ree1;
        return r;
    }
    else if (ree1 != 0) {
        littcomplexe* r = new littcomplexe(*(this->getPartRe()) + ree1, this->getPartIm());
        delete rat1;
        delete ent1;
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
        delete rat1;
        delete ree1;
        return r;
    }
    else if (rat1 != 0) {
        littcomplexe* r = new littcomplexe(*(this->getPartRe()) - rat1, this->getPartIm());
        delete ent1;
        delete ree1;
        return r;
    }
    else if (ree1 != 0) {
        littcomplexe* r = new littcomplexe(*(this->getPartRe()) - ree1, this->getPartIm());
        delete rat1;
        delete ent1;
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
        delete rat1;
        delete ree1;
        return r;
    }
    else if (rat1 != 0) {
        littcomplexe* r = new littcomplexe(*(this->getPartRe()) * rat1, *(this->getPartIm()) * rat1);
        delete ent1;
        delete ree1;
        return r;
    }
    else if (ree1 != 0) {
        littcomplexe* r = new littcomplexe(*(this->getPartRe()) * ree1, *(this->getPartIm()) * ree1);
        delete rat1;
        delete ent1;
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
        delete rat1;
        delete ree1;
        return r;
    }
    else if (rat1 != 0) {
        littcomplexe* r = new littcomplexe(*(this->getPartRe()) / rat1, *(this->getPartIm()) / rat1);
        delete ent1;
        delete ree1;
        return r;
    }
    else if (ree1 != 0) {
        littcomplexe* r = new littcomplexe(*(this->getPartRe()) / ree1, *(this->getPartIm()) / ree1);
        delete rat1;
        delete ree1;
        return r;
    }
    else {
        return 0;
    }
}
