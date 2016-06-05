#include "littentiere.h"

littEntiere& littEntiere::operator+(littEntiere& b)
{
    littEntiere* res = new littEntiere(this->valeur + b.valeur);
    return (*res); // int + int = int
}

littEntiere& littEntiere::operator-(littEntiere& b)
{
    littEntiere* res = new littEntiere(this->valeur - b.valeur);
    return (*res); // int - int = int
}

littEntiere& littEntiere::operator*(littEntiere& b)
{
    littEntiere* res = new littEntiere(this->valeur * b.valeur);
    return (*res); //int*int = int
}

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
        valeur = valeur + ent1->getValeur();
        return this;
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
        valeur = valeur - ent1->getValeur();
        return this;
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
        littcomplexe* res2 = new littcomplexe((*this) * ltc->getPartRe(), (*this) * ltc->getPartIm());
        return res2;
    }
}

littNumerique* littEntiere::operator*(littNumerique* a)
{

    if (this->getValeur() == 0) {
        littEntiere* res = new littEntiere(0);
        return res;
    }
    littEntiere* ent1 = dynamic_cast<littEntiere*>(a);

    littrat* rat1 = dynamic_cast<littrat*>(a);

    littReelle* ree1 = dynamic_cast<littReelle*>(a);

    if (ent1 != 0) {
        valeur = valeur * ent1->getValeur();
        return this;
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
    else {
        return 0;
    }
}
