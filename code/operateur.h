/**
\file operateur.h
\date 03/06/2016
\author LoÃ¯c Lerat, Andr�a Vibert, Th�o Hordequin
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
  \brief La classe est la classe m�re de tous les types d'operateurs
 */
class operateur : public Operande {
protected:
    //! \brief Attribut :
    //! arite : \e int concernant l'arit� de l'op�rateur
    int arite;

    //! \brief Attribut :
    //! symbol : \e QString concernant le nom de l'op�rateur
    QString symbol;

public:
    //! \brief  Constructeur de l'op�rateur
    //! \param  f QString
    //! \param  a int
    operateur(int a, QString s): arite(a), symbol(s){}

    //! \brief  Getter de l'arit� de l'op�rateur
    //! \return  int correspondant � l'arit� de l'op�rateur
    int getArite() { return arite; }

    //! \brief  Getter du symbol de l'op�rateur
    //! \return  QString correspondant au nom de l'op�rateur
    QString getSymbol() { return symbol; }

    //! \brief  Traitement de l'op�rateur, m�thode qui ex�cute le fonctionnement de l'op�rateur || Cas arit� 2. Elle est red�fini dans toutes les classes filles
    //! \param a litterale& -> premi�re litt�rale en argument
    //! \param b litterale& -> seconde litt�rale en argument
    //! \return  un \e litterale& correspondant � une r�f�rence vers une litterale cr�e par le traitement
    virtual litterale& traitement(litterale& a, litterale& b) = 0;

    //! \brief  Traitement de l'op�rateur, m�thode qui ex�cute le fonctionnement de l'op�rateur || Cas arit� 1. Elle est red�fini dans toutes les classes filles
    //! \param a litterale& -> litt�rale en argument
    //! \return  un \e litterale& correspondant � une r�f�rence vers une litterale cr�e par le traitement
    virtual litterale& traitement(litterale& a) = 0;


    //! \brief  Traitement de l'op�rateur, m�thode qui ex�cute le fonctionnement de l'op�rateur || Cas arit� 0. Elle est red�fini dans toutes les classes filles
    //!
    virtual void traitement() = 0;

};

/*******************OPERATEURS NUMERIQUES*****************************************/
/**
  \class operateur_numerique
  \brief La classe m�re de tous les op�rateurs numerique
 */
class operateur_numerique : public operateur {
public:
    //! \brief  Constructeur de l'op�rateur numerique -> fait appel au constructeur de la classe operateur
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
  \brief La classe d'op�rateur qui effectue l'addition entre 2 litt�rales
  (+)
 */
class add : public operateur_numerique{
public:

    //! \brief Constructeur de l'op�rateur -> appel du construteur d'op�rateur numerique
    add():operateur_numerique(2,"+"){}

    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale& a){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");
    }
    void traitement(){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");
    }
};

/******************* - : Soustraction **************************************/

/**
  \class sous
  \brief La classe d'op�rateur qui effectue l'addition entre 2 litt�rales
  (+)
 */
class sous : public operateur_numerique{
public:
    //! \brief Constructeur de l'op�rateur -> appel du construteur d'op�rateur numerique
    sous():operateur_numerique(2,"-"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");}
    void traitement(){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");
    }
};

/************************************************************/

/**
  \class den
  \brief La classe d'op�rateur qui renvoye le d�nominateur d'un litterale rationnelle ou un entier dans le cas litterale enti�re
  (DEN)
 */
class den : public operateur_numerique
{
public:
    //! \brief Constructeur de l'op�rateur -> appel du construteur d'op�rateur numerique
    den():operateur_numerique(1,"DEN"){}
    litterale& traitement(litterale &a, litterale &b){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");}
    litterale& traitement(litterale &a);
    void traitement(){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");
    }
};
/**********************************************************/


/**
  \class divent
  \brief La classe d'op�rateur qui renvoye le r�sultat de la division enti�re de 2 litterales entieres
  (DIV)
 */
class divent : public operateur_numerique
{
public:
    //! \brief Constructeur de l'op�rateur -> appel du construteur d'op�rateur numerique
    divent():operateur_numerique(2,"DIV"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");}
    void traitement(){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");
    }
};

/**********************************************************/


/**
  \class divs
  \brief La classe d'op�rateur qui renvoye le r�sultat de la division de 2 litterales
  (/)
 */
class divs : public operateur_numerique
{
public:
    //! \brief Constructeur de l'op�rateur -> appel du construteur d'op�rateur numerique
    divs():operateur_numerique(2,"/"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");}
    void traitement(){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");
    }
};

/********************************************************************/


/**
  \class dollar
  \brief La classe d'op�rateur qui renvoye une litt�rale complexe form�e des 2 litterales d�pil�es
  ($)
 */
class dollar : public operateur_numerique
{
public:
    //! \brief Constructeur de l'op�rateur -> appel du construteur d'op�rateur numerique
    dollar():operateur_numerique(2,"$"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");}
    void traitement(){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");
    }
};

/************************************************************************/
/**
  \class mod
  \brief La classe d'op�rateur qui renvoye le r�sultat du modulo de 2 litterales
  (MOD)
 */

class mod : public operateur_numerique
{
public:
    //! \brief Constructeur de l'op�rateur -> appel du construteur d'op�rateur numerique
    mod():operateur_numerique(2,"MOD"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");}
    void traitement(){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");
    }
};

/**************************************************************************/
/**
  \class mul
  \brief La classe d'op�rateur qui renvoye le r�sultat de la multiplication de 2 litterales
  (*)
 */

class mul : public operateur_numerique
{
public:
    //! \brief Constructeur de l'op�rateur -> appel du construteur d'op�rateur numerique
    mul():operateur_numerique(2,"*"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");}
    void traitement(){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");
    }
};

/*********************************************************************************/


/**
  \class neg
  \brief La classe d'op�rateur qui renvoye la valeur n�gative de la litt�rale
  (NEG)
 */
class neg : public operateur_numerique
{
public:
    //! \brief Constructeur de l'op�rateur -> appel du construteur d'op�rateur numerique
    neg():operateur_numerique(1,"NEG"){}
    litterale& traitement(litterale &a, litterale &b){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");}
    litterale& traitement(litterale &a);
    void traitement(){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");
    }
};


/*********************************************************************************/


/**
  \class num
  \brief La classe d'op�rateur qui renvoye la valeur du numerateur de la litt�rale
  (NEG)
 */

class num : public operateur_numerique
{
public:
    //! \brief Constructeur de l'op�rateur -> appel du construteur d'op�rateur numerique
    num():operateur_numerique(1,"NUM"){}
    litterale& traitement(litterale &a, litterale &b){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");}
    litterale& traitement(litterale &a);
    void traitement(){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");
    }
};

/***********************************************************************************/


/**
  \class opim
  \brief La classe d'op�rateur qui renvoye la partie imaginaire de la litterale complexe
  (IM)
 */

class opim : public operateur_numerique
{
public:
    //! \brief Constructeur de l'op�rateur -> appel du construteur d'op�rateur numerique
    opim():operateur_numerique(1,"IM"){}
    litterale& traitement(litterale &a, litterale &b){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");}
    litterale& traitement(litterale &a);
    void traitement(){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");
    }
};


/********************************************************************************/

 /**
  \class opre
  \brief La classe d'op�rateur qui renvoye la partie r�elle de la litterale complexe
  (RE)
 */

class opre : public operateur_numerique
{
public:
    //! \brief Constructeur de l'op�rateur -> appel du construteur d'op�rateur numerique
    opre():operateur_numerique(1,"RE"){}
    litterale& traitement(litterale &a, litterale &b){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");}
    litterale& traitement(litterale &a);
    void traitement(){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");
    }
};


/****************************************************************************/
/*******ope logiques********/

/**
  \class operateur_logique
  \brief La classe m�re de tous les op�rateurs logiques
 */
class operateur_logique : public operateur {
public:
    //! \brief  Constructeur de l'op�rateur logique -> fait appel au constructeur de la classe operateur
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
  \brief La classe d'op�rateur qui renvoye la resultat de l'op�rateur AND
  (AND)
 */

class opand : public operateur_logique
{
public:
    //! \brief Constructeur de l'op�rateur -> appel du construteur d'op�rateur logique
    opand():operateur_logique(2,"AND"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");}
    void traitement(){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");
    }
};

/******************************************************************************/


/**
  \class opdiff
  \brief La classe d'op�rateur qui renvoye la resultat de l'op�rateur diff�rent
  (!=)
 */

class opdiff : public operateur_logique
{
public:
    //! \brief Constructeur de l'op�rateur -> appel du construteur d'op�rateur logique
    opdiff():operateur_logique(2,"!="){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");}
    void traitement(){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");
    }
};

/*****************************************************************************************************************/

/**
  \class opegal
  \brief La classe d'op�rateur qui renvoye la resultat de l'op�rateur d'�galit�
  (=)
 */

class opegal : public operateur_logique
{
public:
    //! \brief Constructeur de l'op�rateur -> appel du construteur d'op�rateur logique
    opegal():operateur_logique(2,"="){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");}
    void traitement(){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");
    }
};

/******************************************************************************************************************/
/**
  \class opegalsup
  \brief La classe d'op�rateur qui renvoye la resultat de l'op�rateur sup�rieur ou �gale
  (>=)
 */

class opegalsup : public operateur_logique
{
public:
    //! \brief Constructeur de l'op�rateur -> appel du construteur d'op�rateur logique
    opegalsup():operateur_logique(2,">="){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");}
    void traitement(){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");
    }
};

/********************************************************************************************************************/

/**
  \class opegalinf
  \brief La classe d'op�rateur qui renvoye la resultat de l'op�rateur inf�rieur ou �gale
  (=<)
 */

class opegalinf : public operateur_logique
{
public:
    //! \brief Constructeur de l'op�rateur -> appel du construteur d'op�rateur logique
    opegalinf():operateur_logique(2,"=<"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");}
    void traitement(){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");
    }
};



/********************************************************************************************************************/
/**
  \class opinf
  \brief La classe d'op�rateur qui renvoye le r�sultat de la comparaison par le signe inf�rieur
  (<)
 */

class opinf : public operateur_logique
{
public:
    //! \brief Constructeur de l'op�rateur -> appel du construteur d'op�rateur logique
    opinf():operateur_logique(2,"<"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");}
    void traitement(){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");
    }
};
/****************************************************************************************************************/
/**
  \class opnot
  \brief La classe d'op�rateur qui renvoye le r�sultat de la comparaison par l'op�rateur NOT
  (NOT)
 */

class opnot : public operateur_logique
{
public:
    //! \brief Constructeur de l'op�rateur -> appel du construteur d'op�rateur logique
    opnot():operateur_logique(1,"NOT"){}

    void traitement(){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");
    }
    litterale& traitement(litterale &a);
    litterale& traitement(litterale &a, litterale &b){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");}
};

/******************************************************************************/

/**
  \class opor
  \brief La classe d'op�rateur qui renvoye le r�sultat de la comparaison par l'op�rateur OR
  (OR)
 */

class opor : public operateur_logique
{
public:
    //! \brief Constructeur de l'op�rateur -> appel du construteur d'op�rateur logique
    opor():operateur_logique(2,"OR"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");}
    void traitement(){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");
    }
};

/**********************************************************************************/
/**
  \class opsup
  \brief La classe d'op�rateur qui renvoye le r�sultat de la comparaison par le signe sup�rieur
  (<)
 */

class opsup : public operateur_logique
{
public:
    //! \brief Constructeur de l'op�rateur -> appel du construteur d'op�rateur logique
    opsup():operateur_logique(2,">"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");}
    void traitement(){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");
    }
};

/**************************************************************************************************/

/**
  \class operateur_pile
  \brief La classe m�re de tous les op�rateurs concernant la pile
 */
class operateur_pile : public operateur {
public:
    //! \brief  Constructeur de l'op�rateur de pile -> fait appel au constructeur de la classe operateur
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
  \brief La classe d'op�rateur qui renvoye la resultat de l'�valuation de la litterale programme
  (EVAL)
 */

class opeval : public operateur_numerique
{
public:
    //! \brief Constructeur de l'op�rateur -> appel du construteur d'op�rateur numerique
    opeval():operateur_numerique(1,"EVAL"){}
    litterale& traitement(litterale &a, litterale &b){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");}
    litterale& traitement(litterale &a);
    void traitement(){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");
    }
};
/******************************************************************************************************/
/**
  \class opdup
  \brief La classe d'op�rateur qui renvoye la resultat de l'op�rateur duplication
  (DUP)
 */

class opdup : public operateur_pile
{
public:
    //! \brief Constructeur de l'op�rateur -> appel du construteur d'op�rateur logique
    opdup():operateur_pile(0,"DUP"){}
    litterale& traitement(litterale &a, litterale &b){
    throw ComputerException("Arit� incorrecte pour cet op�rateur");
    }
    litterale& traitement(litterale &a){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");}
    void traitement();
};


/******************************************************************************************************************/
/**
  \class operateur_conditionnel
  \brief La classe m�re de tous les op�rateurs conditionnels
 */
class operateur_conditionnel : public operateur {
public:
    //! \brief  Constructeur de l'op�rateur conditionnel -> fait appel au constructeur de la classe operateur
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
  \brief La classe d'op�rateur conditionnel IFT. Si le 1er argument (dernier d�pil�) est 1, on execute le programme, sinon on abandonne
 */

class opIft : public operateur_conditionnel
{
public:
    //! \brief Constructeur de l'op�rateur -> appel du construteur d'op�rateur conditionnel
    opIft():operateur_conditionnel(2,"IFT"){}
    litterale& traitement(litterale &a, litterale &b);
    litterale& traitement(litterale &a){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");}
    void traitement(){
        throw ComputerException("Arit� incorrecte pour cet op�rateur");
    }
};

/****************************************************************************************************************/
#endif // OPERATEUR_H
