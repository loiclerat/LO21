/**
\file litterale.h
\date 03/06/2016
\author Loïc Lerat, Andréa Vibert, Théo Hordequin
\version 1.0
\brief  Classe litterale

Description de la classe Litterale

**/


#ifndef LITTERALE_H
#define LITTERALE_H


#include <QString>
#include <QTextStream>
#include <QObject>
#include <QDebug>

#include "exceptions.h"
#include <typeinfo>
#include <iostream>
#include <string>
#include "operande.h"


using namespace std;

/**
  \class litterale
  \brief La classe est la classe mère de tous les types de littérales
 */
class litterale : public Operande{
public :
    //! \brief       Affichage de la litterale
    //! \param    f         QString
    //! \return    Un \e QString possédant tout l'affichage de la litterale.
    //!
    virtual QString affichage(QString f="")const=0;
    //! \brief       Simplification de la litterale
    //!
    virtual litterale* simplifier(){return this;}/*permet de simplifier les litt num
    *dàs leur cràation, àventuellement les transformer en une autre litt num
    *si possible.
    */
    //! \brief       Détermine si la litterale est nulle ou non.
    //! \return    Un \e booléen : true si la litterale est nulle, faux sinon.
    //!
    virtual bool isNull()=0;

    virtual litterale& operator=(litterale& a)=0;
};

/**
  \class littnumber
  \brief La classe correspond è  toutes les littèrales correspondant aux nombres
 */
class littnumber : public litterale
{
public:
    virtual ~littnumber(){}


    virtual QString affichage(QString f="")const=0;//a definir
    virtual litterale* simplifier(){return this;}
    virtual bool isNull()=0;
    //! \brief       Dètermine si la littèrale nombre est positive.
    //! \return    Un \e boolèen : true si la litterale est nulle, faux sinon.
    //!
    virtual bool isPos()=0;

    //! \brief       Operator + de la litterale concernant l'addition
    //! \param    a         littnumber*
    //! \return    Un \e littnumber* -> pointeur vers une littèrale number qui contient la construction concrète d'un objet fille.
    //!
    virtual littnumber* operator+(littnumber* a)=0;
    //! \brief       Operator - de la litterale concernant la soustraction
    //! \param    a         littnumber*
    //! \return    Un \e littnumber* -> pointeur vers une littèrale number qui contient la construction concrète d'un objet fille.
    //!
    virtual littnumber* operator-(littnumber* a)=0;

    //! \brief       Operator + de la litterale concernant la multiplication
    //! \param    a         littnumber*
    //! \return    Un \e littnumber* -> pointeur vers une littèrale number qui contient la construction concrète d'un objet fille.
    //!
    virtual littnumber* operator*(littnumber* a)=0;
    //! \brief       Operator + de la litterale concernant la division
    //! \param    a         littnumber*
    //! \return    Un \e littnumber* -> pointeur vers une littèrale number qui contient la construction concrète d'un objet fille.
    //!
    virtual littnumber* operator/(littnumber* a)=0;


};

/**
  \class littNumerique
  \brief La classe correspond à  toutes les littérales correspondant aux littérales numériques
 */
class littNumerique : public littnumber{

public :

    // **************************************** //
    //          Défini précédemment
    // **************************************** //
    virtual QString affichage(QString f="")const=0;//a definir
    virtual litterale* simplifier(){return this;}
    virtual bool isNull()=0;
    virtual bool isPos()=0;

    virtual littnumber* operator+(littnumber* a)=0;
    littnumber* operator-(littnumber* a);
    virtual littnumber* operator*(littnumber* a)=0;
    virtual littnumber* operator/(littnumber* a)=0;

    // **************************************** //

    //! \brief       Operator + de la litterale concernant l'addition
    //! \details    Surchage qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument).
    //! \param    a         littNumerique*
    //! \return    Un \e littNumerique* -> pointeur vers une littérale numérique qui contient la construction concrète d'un objet fille.
    //!
    virtual littNumerique* operator+(littNumerique* a)=0;

    //! \brief       Operator - de la litterale concernant la soustraction
    //! \details    Surchage qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument).
    //! \param    a         littNumerique*
    //! \return    Un \e littNumerique* -> pointeur vers une littérale numérique qui contient la construction concrète d'un objet fille.
    //!
    virtual littNumerique* operator-(littNumerique* a)=0;
    //! \brief       Operator * de la litterale concernant la multiplication
    //! \details    Surchage qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument).
    //! \param    a         littNumerique*
    //! \return    Un \e littNumerique* -> pointeur vers une littérale numérique qui contient la construction concrète d'un objet fille.
    //!
    virtual littNumerique* operator*(littNumerique* a)=0;

    //! \brief       Operator / de la litterale concernant la division
    //! \details    Surchage qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument).
    //! \param    a         littNumerique*
    //! \return    Un \e littNumerique* -> pointeur vers une littérale numérique qui contient la construction concrète d'un objet fille.
    //!
    virtual littNumerique* operator/(littNumerique* a)=0;

    virtual littNumerique& operator=(littNumerique& a)=0;
};


/**
  \class littEntiere
  \brief La classe concernant les littérales entières
 */

class littEntiere : public littNumerique {
    //! \brief Attribut :
    //! valeur : \e int concernant la valeur du littérale entier
    int valeur;

public:
    //! \brief Constructeur de littérale entière
    //! \param    val         int
    littEntiere(int val)
        : valeur(val)
    {
    }
    //! \brief Destructeur de littérale entière
    ~littEntiere() {}
    //! \brief       Getter
    //! \return    Un \e entier possédant le contenue de la littérale.
    //!
    int getValeur() const { return valeur; }

    bool isNull(){
        if(valeur==0){
            return true;
        }
        else return false;
    }

    bool isPos(){
        if(valeur>0){
            return true;
        }
        else return false;
    }



    QString affichage(QString f = "") const
    {
        f.append(QString::number(getValeur()));
        return f;
    }

    /*==========*/
    littNumerique* operator+(littNumerique* a);
    littnumber* operator+(littnumber* a);
    /*==========*/
    littNumerique* operator-(littNumerique* a);
    littnumber* operator-(littnumber* a);
    /*==========*/
    littNumerique* operator*(littNumerique* a);
    littnumber* operator*(littnumber* a);
    /*==========*/
    //! \brief       Operator / de la litterale concernant la division entière
    //! \details    Surchage qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument)
    //!             renvoi un littérale numérique qui correspond à  un rationnel
    //! \param    a         littEntiere*
    //! \return    Un \e littNumerique* -> pointeur vers une littérale numérique qui contient la construction concrète d'un objet fille.
    //!
    littNumerique* operator/(littEntiere* b);
    littNumerique* operator/(littNumerique* a);
    littnumber* operator/(littnumber* a);
    /*==========*/

    litterale& operator=(litterale& a){
        littEntiere* le = dynamic_cast<littEntiere*>(&a);
        if(le != 0){
            littEntiere* ret = new littEntiere(le->getValeur());
            return *ret;
        }
    }

    littNumerique& operator=(littNumerique& a){
        littEntiere* le = dynamic_cast<littEntiere*>(&a);
        if(le != 0){
            littEntiere* ret = new littEntiere(le->getValeur());
            return *ret;
        }
    }


};

/**
  \class littrat
  \brief La classe des littérales rationnelles
 */
class littrat : public littNumerique {
    //! \brief Attribut :
    //! num : \e int concernant le numerateur de la littérale rationnelle
    int num;
    //! \brief Attribut :
    //! den : \e int concernant le denominateur de la littérale rationnelle
    int den;

public:
    //! \brief Constructeur de littérale rationnelle (arguments : n = numérateur, d = dénominateur
    //! \param    n         int
    //! \param    d         int
    littrat(int n = 0, int d = 1)
    {
        num = n;
        den = d;
    }
    //! \brief Destructeur de littérale rationnelle
    ~littrat() {}
    litterale* simplifier();

    //! \brief Getter du numérateur
    //! \return    Un \e entier possédant le contenue du numérateur.
    int getNum() const { return num; }
    //! \brief Getter du dénominateur
    //! \return    Un \e entier possédant le contenue du dénominateur.
    int getDen() const { return den; }
    //! \brief Getter de la valeur réelle
    //! \return    Un \e float possédant le contenue du rationnelle.
    float getValeur() const { return num / den; }

    bool isNull()
    {
        if (num == 0) return true;
        else return false;
    }

    bool isPos()
    {
        if (num > 0) return true;
        else return false;
    }

    QString affichage(QString f = "") const
    {
        f.append(QString::number(getNum()));
        f.append("/");
        f.append(QString::number(getDen()));
        return f;
    }

    /*==========*/
    //! \brief       Operator + de la litterale concernant l'addition
    //! \details    Surchage qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument)
    //!             renvoi une littérale rationnelle
    //! \param    b         littrat*
    //! \return    Un \e littrat* -> pointeur vers une littérale rationnelle qui contient la construction concrète d'un objet fille.
    //!
    littrat* operator+(littrat* b);
    littNumerique* operator+(littNumerique* a);
    littnumber* operator+(littnumber* a);
    /*==========*/
    //! \brief       Operator - de la litterale concernant la soustraction
    //! \details    Surchage de la classe qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument)
    //!             renvoi une littérale rationnelle
    //! \param    b         littrat*
    //! \return    Un \e littrat* -> pointeur vers une littérale rationnelle qui contient la construction concrète d'un objet fille.
    //!
    littrat* operator-(littrat* b);
    littNumerique* operator-(littNumerique* a);
    littnumber* operator-(littnumber* a);
    /*==========*/
    //! \brief       Operator * de la litterale concernant la multiplication
    //! \details    Surchage de la classe qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument)
    //!             renvoi une littérale rationnelle
    //! \param    b         littrat*
    //! \return    Un \e littrat* -> pointeur vers une littérale rationnelle qui contient la construction concrète d'un objet fille.
    //!
    littrat* operator*(littrat* b);
    littNumerique* operator*(littNumerique* a);
    littnumber* operator*(littnumber* a);
    /*==========*/
    //! \brief       Operator / de la litterale concernant la division
    //! \details    Surchage de la classe qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument)
    //!             renvoi une littérale rationnelle
    //! \param    b         littrat*
    //! \return    Un \e littrat* -> pointeur vers une littérale rationnelle qui contient la construction concrète d'un objet fille.
    //!
    littrat* operator/(littrat* b);
    littNumerique* operator/(littNumerique* a);
    littnumber* operator/(littnumber* a);
    /*==========*/

    litterale& operator=(litterale& a){
        littrat* le = dynamic_cast<littrat*>(&a);
        if(le != 0){
            littrat* ret = new littrat(le->getNum(),le->getDen());
            return *ret;
        }
    }

    littNumerique& operator=(littNumerique& a){
        littrat* le = dynamic_cast<littrat*>(&a);
        if(le != 0){
            littrat* ret = new littrat(le->getNum(),le->getDen());
            return *ret;
        }
    }
};

/**
\file littreelle.h
\date 03/06/2016
\author LoÃ¯c Lerat, Andréa Vibert, Théo Hordequin
\version 1.0
\brief  Classe littreelle

Description de la classe litterale réelle

**/

/**
  \class littReelle
  \brief La classe correspond aux littérales réelles
 */
class littReelle : public littNumerique {
    float valeur;
    int entiere;
    float decimale;

public:
    //! \brief Constructeur de littérale réelle ( arguments : e = entier (matisse), d = réel (décimale) )
    //! \param    e         int
    //! \param    d         float
    littReelle(int e, float d): valeur(e + d), entiere(e), decimale(d){}

    //! \brief Constructeur de littérale réelle ( arguments : d = réelle (décimale))
    //! \param    d         float
    littReelle(float d): valeur(d), entiere(0), decimale(d){} //Ex : ne prend que les .45 et le traduit directement comme un 0.45

    //! \brief Destructeur de littérale réelle
    ~littReelle() {}

    //! \brief Getter de la valeur du réelle
    //! \return    Un \e float possédant le contenue de la littérale.
    float getValeur() const { return valeur; }
    //! \brief Getter de la matisse du réelle
    //! \return    Un \e entier possédant le contenue de la matisse.
    int getEntiere() const { return entiere; }
    //! \brief Getter de la décimale du réelle
    //! \return    Un \e entier possédant le contenue de la décimale.
    float getDecimale() const { return decimale; }
    litterale* simplifier();

    bool isNull(){
        if(valeur==0.0){
            return true;
        }
        else return false;
    }

    bool isPos(){
        if(valeur>0){
            return true;
        }
        else return false;
    }

    QString affichage(QString f = "") const
    {
        f.append(QString::number(getValeur()));
        return f;
    }

    /*==========*/
    //! \brief       Operator + de la litterale concernant l'addition
    //! \details    Surchage de la classe spécifique qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument)
    //!             renvoi une littérale rationnelle
    //! \param    b         littReelle*
    //! \return    Un \e littReelle* -> pointeur vers une littérale réelle qui contient la construction concrète d'un objet fille.
    //!
    littReelle* operator+(littReelle* b);
    littNumerique* operator+(littNumerique* b);
    littnumber* operator+(littnumber* b);
    /*==========*/
    //! \brief       Operator - de la litterale concernant la soustraction
    //! \details    Surchage de la classe spécifique qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument)
    //!             renvoi une littérale rationnelle
    //! \param    b         littReelle*
    //! \return    Un \e littReelle* -> pointeur vers une littérale réelle qui contient la construction concrète d'un objet fille.
    //!
    littReelle* operator-(littReelle* b);
    littNumerique* operator-(littNumerique* b);
    littnumber* operator-(littnumber* b);
    /*==========*/
    //! \brief       Operator * de la litterale concernant la multiplication
    //! \details    Surchage de la classe spécifique qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument)
    //!             renvoi une littérale rationnelle
    //! \param    b         littReelle*
    //! \return    Un \e littReelle* -> pointeur vers une littérale réelle qui contient la construction concrète d'un objet fille.
    //!
    littReelle* operator*(littReelle* b);
    littNumerique* operator*(littNumerique* b);
    littnumber* operator*(littnumber* b);
    /*==========*/
    //! \brief       Operator / de la litterale concernant la division
    //! \details    Surchage de la classe spécifique qui permet un niveau de granularité plus fin afin de construire l'objet qui convient en sorti d'operateur. (resp argument)
    //!             renvoi une littérale rationnelle
    //! \param    b         littReelle*
    //! \return    Un \e littReelle* -> pointeur vers une littérale réelle qui contient la construction concrète d'un objet fille.
    //!
    littReelle* operator/(littReelle* b);
    littNumerique* operator/(littNumerique* b);
    littnumber* operator/(littnumber* b);
    /*==========*/

    litterale& operator=(litterale& a){
        littReelle* le = dynamic_cast<littReelle*>(&a);
        if(le != 0){
            littReelle* ret = new littReelle(le->getValeur());
            return *ret;
        }
    }

    littNumerique& operator=(littNumerique& a){
        littReelle* le = dynamic_cast<littReelle*>(&a);
        if(le != 0){
            littReelle* ret = new littReelle(le->getValeur());
            return *ret;
        }
    }
};


/**
  \class littcomplexe
  \brief La classe concernant les littérales complexes
 */
class littcomplexe : public littnumber {

    //! \brief Attribut :
    //! partRe : \e littNumerique* concernant la partie réelle du complexe
    littNumerique* partRe;

    //! \brief Attribut :
    //! partIm : \e littNumerique* concernant la partie imaginaire du complexe
    littNumerique* partIm;

public:
    //! \brief Constructeur de littérale complexe
    //! \param    b             littNumerique*
    //! \param    a             littNumerique*
    littcomplexe(littNumerique* a, littNumerique* b):partRe(a),partIm(b){}

    //! \brief Constructeur de recopie littérale complexe
    littcomplexe(littcomplexe const&);

    //! \brief Destructeur de littérale complexe
    ~littcomplexe(){}


    //! \brief Getter de la partie réelle
    //! \return    Un \e littNumerique* possédant le contenue de la partie réelle.
    littNumerique* getPartRe() const { return partRe; }
    //! \brief Getter de la partie imaginaire
    //! \return    Un \e littNumerique* possédant le contenue de la partie imaginaire.
    littNumerique* getPartIm() const { return partIm; }

    litterale* simplifier();

    bool isNull(){
        if(partRe->isNull()==true)
            if(partIm->isNull()==true) return true;
        return false;
    }

    bool isPos(){
        if(partRe->isPos()==true){
            if(partIm->isPos()==true){
                return true;
            }else return false;
        }
        else return false;
    }


    QString affichage(QString f = "") const
    {
        f.append(getPartRe()->affichage());
        f.append("$");
        f.append(getPartIm()->affichage());
        return f;
    }
    /*==========*/
    littnumber* operator+(littnumber* a);
    /*==========*/
    littnumber* operator-(littnumber* a);
    /*==========*/
    littnumber* operator*(littnumber* a);
    /*==========*/
    littnumber* operator/(littnumber* a);

    litterale& operator=(litterale& a){
        littcomplexe* lc = dynamic_cast<littcomplexe*>(&a);

        if(lc != 0){
            littNumerique* re = lc->getPartRe();
            littNumerique* im = lc->getPartIm();
            littcomplexe* res = new littcomplexe(re,im);
            return *res;
        }
    }
};



/**
  \class littProgramme
  \brief La classe des littérales programmes
 */
class littProgramme : public litterale
{
    //! \brief Attribut :
    //! str : \e QString concernant la chaine de caractère du programme
    QString str;
public:

    //! \brief Constructeur de littérale programme
    //! \param    s         QString
    littProgramme(QString s):str(s){}

    //! \brief Destructeur de littérale programme
    ~littProgramme(){}

    QString affichage(QString f="")const{
        f.append(str);
        return f;
    }

    //! \brief       Getter
    //! \return    Un \e QString possédant le contenue de la littérale.
    //!
    QString getStr(){
        return str;
    }

    bool isNull(){
        if(str == "")return true;
        else return false;
    }

    litterale& operator=(litterale& a){
        littProgramme* le = dynamic_cast<littProgramme*>(&a);
        if(le != 0){
            littProgramme* ret = new littProgramme(le->getStr());
            return *ret;
        }
    }
};

#endif // LITTERALE_H
