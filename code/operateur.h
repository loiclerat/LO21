/**
\file operateur.h
\date 03/06/2016
\author Loïc Lerat, Andréa Vibert, Théo Hordequin
\version 1.0
\brief  Classe operateur

Description de la classe Operateur

**/

#ifndef OPERATEUR_H
#define OPERATEUR_H
#include "litterale.h"
#include "QString"
#include "exceptions.h"
#include "pile.h"
#include "operande.h"

/**
  \class operateur
  \brief La classe est la classe mère de tous les types d'operateurs
 */
class operateur : public Operande {
protected:
    //! \brief Attribut :
    //! arite : \e int concernant l'arité de l'opérateur
    int arite;

    //! \brief Attribut :
    //! symbol : \e QString concernant le nom de l'opérateur
    QString symbol;

public:
    //! \brief  Constructeur de l'opérateur
    //! \param  f QString
    //! \param  a int
    operateur(int a, QString s): arite(a), symbol(s){}

    //! \brief  Getter de l'arité de l'opérateur
    //! \return  int correspondant à l'arité de l'opérateur
    int getArite() { return arite; }

    //! \brief  Getter du symbol de l'opérateur
    //! \return  QString correspondant au nom de l'opérateur
    QString getSymbol() { return symbol; }

    //! \brief  Traitement de l'opérateur, méthode qui exécute le fonctionnement de l'opérateur || Cas arité 2. Elle est redéfini dans toutes les classes filles
    //! \param a litterale& -> première littérale en argument
    //! \param b litterale& -> seconde littérale en argument
    //! \return  un \e litterale& correspondant à une référence vers une litterale crée par le traitement
    virtual litterale& traitement(litterale& a, litterale& b) = 0;

    //! \brief  Traitement de l'opérateur, méthode qui exécute le fonctionnement de l'opérateur || Cas arité 1. Elle est redéfini dans toutes les classes filles
    //! \param a litterale& -> littérale en argument
    //! \return  un \e litterale& correspondant à une référence vers une litterale crée par le traitement
    virtual litterale& traitement(litterale& a) = 0;


    //! \brief  Traitement de l'opérateur, méthode qui exécute le fonctionnement de l'opérateur || Cas arité 0. Elle est redéfini dans toutes les classes filles
    //!
    virtual void traitement() = 0;

};

/*******************OPERATEURS NUMERIQUES*****************************************/
/**
  \class operateur_numerique
  \brief La classe mère de tous les opérateurs numerique
 */
class operateur_numerique : public operateur {
public:
    //! \brief  Constructeur de l'opérateur numerique -> fait appel au constructeur de la classe operateur
    //! \param  f QString
    //! \param  a int
    operateur_numerique(int a, QString s): operateur(a, s){}

    virtual litterale& traitement(litterale& a, litterale& b) = 0;
    virtual litterale& traitement(litterale& a) = 0;
    virtual void traitement() = 0;
};


/************************** + : addition ******************************************/

/**
  \class add
  \brief La classe d'opérateur qui effectue l'addition entre 2 littérales
  (+)
 */
class add : public operateur_numerique{
public:

    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur numerique
    add():operateur_numerique(2,"+"){}

    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale& a){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};

/******************* - : Soustraction **************************************/

/**
  \class sous
  \brief La classe d'opérateur qui effectue l'addition entre 2 littérales
  (+)
 */
class sous : public operateur_numerique{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur numerique
    sous():operateur_numerique(2,"-"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};

/************************************************************/

/**
  \class den
  \brief La classe d'opérateur qui renvoye le dénominateur d'un litterale rationnelle ou un entier dans le cas litterale entière
  (DEN)
 */
class den : public operateur_numerique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur numerique
    den():operateur_numerique(1,"DEN"){}
    litterale& traitement(litterale &a, litterale &b){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    litterale& traitement(litterale &a);
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};
/**********************************************************/


/**
  \class divent
  \brief La classe d'opérateur qui renvoye le résultat de la division entière de 2 litterales entieres
  (DIV)
 */
class divent : public operateur_numerique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur numerique
    divent():operateur_numerique(2,"DIV"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};

/**********************************************************/


/**
  \class divs
  \brief La classe d'opérateur qui renvoye le résultat de la division de 2 litterales
  (/)
 */
class divs : public operateur_numerique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur numerique
    divs():operateur_numerique(2,"/"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};

/********************************************************************/


/**
  \class dollar
  \brief La classe d'opérateur qui renvoye une littérale complexe formée des 2 litterales dépilées
  ($)
 */
class dollar : public operateur_numerique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur numerique
    dollar():operateur_numerique(2,"$"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};

/************************************************************************/
/**
  \class mod
  \brief La classe d'opérateur qui renvoye le résultat du modulo de 2 litterales
  (MOD)
 */

class mod : public operateur_numerique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur numerique
    mod():operateur_numerique(2,"MOD"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};

/**************************************************************************/
/**
  \class mul
  \brief La classe d'opérateur qui renvoye le résultat de la multiplication de 2 litterales
  (*)
 */

class mul : public operateur_numerique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur numerique
    mul():operateur_numerique(2,"*"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};

/*********************************************************************************/


/**
  \class neg
  \brief La classe d'opérateur qui renvoye la valeur négative de la littérale
  (NEG)
 */
class neg : public operateur_numerique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur numerique
    neg():operateur_numerique(1,"NEG"){}
    litterale& traitement(litterale &a, litterale &b){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    litterale& traitement(litterale &a);
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};


/*********************************************************************************/


/**
  \class num
  \brief La classe d'opérateur qui renvoye la valeur du numerateur de la littérale
  (NEG)
 */

class num : public operateur_numerique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur numerique
    num():operateur_numerique(1,"NUM"){}
    litterale& traitement(litterale &a, litterale &b){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    litterale& traitement(litterale &a);
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};

/***********************************************************************************/


/**
  \class opim
  \brief La classe d'opérateur qui renvoye la partie imaginaire de la litterale complexe
  (IM)
 */

class opim : public operateur_numerique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur numerique
    opim():operateur_numerique(1,"IM"){}
    litterale& traitement(litterale &a, litterale &b){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    litterale& traitement(litterale &a);
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};


/********************************************************************************/

 /**
  \class opre
  \brief La classe d'opérateur qui renvoye la partie réelle de la litterale complexe
  (RE)
 */

class opre : public operateur_numerique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur numerique
    opre():operateur_numerique(1,"RE"){}
    litterale& traitement(litterale &a, litterale &b){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    litterale& traitement(litterale &a);
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};


/****************************************************************************/
/*******ope logiques********/

/**
  \class operateur_logique
  \brief La classe mère de tous les opérateurs logiques
 */
class operateur_logique : public operateur {
public:
    //! \brief  Constructeur de l'opérateur logique -> fait appel au constructeur de la classe operateur
    //! \param  f QString
    //! \param  a int
    operateur_logique(int a, QString s)
        : operateur(a, s)
    {
    }

    virtual litterale& traitement(litterale& a, litterale& b) = 0;
    virtual litterale& traitement(litterale& a) = 0;
    virtual void traitement() = 0;
};

/****************************************************************************/

/**
  \class opand
  \brief La classe d'opérateur qui renvoye la resultat de l'opérateur AND
  (AND)
 */

class opand : public operateur_logique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur logique
    opand():operateur_logique(2,"AND"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};

/******************************************************************************/


/**
  \class opdiff
  \brief La classe d'opérateur qui renvoye la resultat de l'opérateur différent
  (!=)
 */

class opdiff : public operateur_logique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur logique
    opdiff():operateur_logique(2,"!="){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};

/*****************************************************************************************************************/

/**
  \class opegal
  \brief La classe d'opérateur qui renvoye la resultat de l'opérateur d'égalité
  (=)
 */

class opegal : public operateur_logique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur logique
    opegal():operateur_logique(2,"="){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};

/******************************************************************************************************************/
/**
  \class opegalsup
  \brief La classe d'opérateur qui renvoye la resultat de l'opérateur supérieur ou égale
  (>=)
 */

class opegalsup : public operateur_logique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur logique
    opegalsup():operateur_logique(2,">="){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};

/********************************************************************************************************************/

/**
  \class opegalinf
  \brief La classe d'opérateur qui renvoye la resultat de l'opérateur inférieur ou égale
  (=<)
 */

class opegalinf : public operateur_logique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur logique
    opegalinf():operateur_logique(2,"=<"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};



/********************************************************************************************************************/
/**
  \class opinf
  \brief La classe d'opérateur qui renvoye le résultat de la comparaison par le signe inférieur
  (<)
 */

class opinf : public operateur_logique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur logique
    opinf():operateur_logique(2,"<"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};
/****************************************************************************************************************/
/**
  \class opnot
  \brief La classe d'opérateur qui renvoye le résultat de la comparaison par l'opérateur NOT
  (NOT)
 */

class opnot : public operateur_logique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur logique
    opnot():operateur_logique(1,"NOT"){}

    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
    litterale& traitement(litterale &a);
    litterale& traitement(litterale &a, litterale &b){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
};

/******************************************************************************/

/**
  \class opor
  \brief La classe d'opérateur qui renvoye le résultat de la comparaison par l'opérateur OR
  (OR)
 */

class opor : public operateur_logique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur logique
    opor():operateur_logique(2,"OR"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};

/**********************************************************************************/
/**
  \class opsup
  \brief La classe d'opérateur qui renvoye le résultat de la comparaison par le signe supérieur
  (<)
 */

class opsup : public operateur_logique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur logique
    opsup():operateur_logique(2,">"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};

/**************************************************************************************************/

/**
  \class operateur_pile
  \brief La classe mère de tous les opérateurs concernant la pile
 */
class operateur_pile : public operateur {
public:
    //! \brief  Constructeur de l'opérateur de pile -> fait appel au constructeur de la classe operateur
    //! \param  f QString
    //! \param  a int
    operateur_pile(int a, QString s): operateur(a, s){}

    virtual litterale& traitement(litterale& a, litterale& b) = 0;
    virtual litterale& traitement(litterale& a) = 0;
    virtual void traitement() = 0;
};
/***********************************************************************************************/
/**********  OPERATEUR DE PILE LUI NORMALEMENT PAS NUMERIQUE, HERTAGE ?!!************************/
/**
  \class opeval
  \brief La classe d'opérateur qui renvoye la resultat de l'évaluation de la litterale programme
  (EVAL)
 */

class opeval : public operateur_numerique
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur numerique
    opeval():operateur_numerique(1,"EVAL"){}
    litterale& traitement(litterale &a, litterale &b){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    litterale& traitement(litterale &a);
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};
/******************************************************************************************************/
/**
  \class opdup
  \brief La classe d'opérateur qui renvoye la resultat de l'opérateur duplication
  (DUP)
 */

class opdup : public operateur_pile
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur logique
    opdup():operateur_pile(0,"DUP"){}
    litterale& traitement(litterale &a, litterale &b){
    throw ComputerException("Arité incorrecte pour cet opérateur");
    }
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    void traitement();
};


/******************************************************************************************************************/
/**
  \class operateur_conditionnel
  \brief La classe mère de tous les opérateurs conditionnels
 */
class operateur_conditionnel : public operateur {
public:
    //! \brief  Constructeur de l'opérateur conditionnel -> fait appel au constructeur de la classe operateur
    //! \param  f QString
    //! \param  a int
    operateur_conditionnel(int a, QString s): operateur(a, s){}

    virtual litterale& traitement(litterale& a, litterale& b) = 0;
    virtual litterale& traitement(litterale& a) = 0;
    virtual void traitement() = 0;
};
/*******************************************************************************************************************/

/**
  \class opIft
  \brief La classe d'opérateur conditionnel IFT. Si le 1er argument (dernier dépilé) est 1, on execute le programme, sinon on abandonne
 */

class opIft : public operateur_conditionnel
{
public:
    //! \brief Constructeur de l'opérateur -> appel du construteur d'opérateur conditionnel
    opIft():operateur_conditionnel(2,"IFT"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arité incorrecte pour cet opérateur");}
    void traitement(){
        throw ComputerException("Arité incorrecte pour cet opérateur");
    }
};

/****************************************************************************************************************/
#endif // OPERATEUR_H
