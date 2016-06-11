
#include "littreelle.h"

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
    if (this->getValeur() == 0.0) {
        littReelle* res = new littReelle(0);
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
    if (this->getValeur() == 0.0) {
        littReelle* res = new littReelle(0);
        return res;
    }
    littEntiere* ent1 = dynamic_cast<littEntiere*>(a);

    littrat* rat1 = dynamic_cast<littrat*>(a);

    littReelle* ree1 = dynamic_cast<littReelle*>(a);

    if (ent1 != 0) {
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
