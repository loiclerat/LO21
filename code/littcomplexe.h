/**
\file littcomplexe.h
\date 03/06/2016
\author LoÃ¯c Lerat, AndrÃ©a Vibert, ThÃ©o Hordequin
\version 1.0
\brief  Classe littcomplexe

Description de la classe litterale complexe

**/


#ifndef LITTCOMPLEXE_H
#define LITTCOMPLEXE_H

#include "littnumber.h"
#include "littnumerique.h"
#include "littentiere.h"
#include "littrat.h"
#include "littreelle.h"

/**
  \class littcomplexe
  \brief La classe concernant les littérales complexes
 */
class littcomplexe : public littnumber {
    littNumerique* partRe;
    littNumerique* partIm;

public:
    //! \brief Constructeur de littérale complexe
    //! \param    b             littNumerique*
    //! \param    a             littNumerique*
    littcomplexe(littNumerique* a, littNumerique* b)
    {
        partRe = a;
        partIm = b;
    }

    //! \brief Constructeur de recopie littérale complexe
    littcomplexe(littcomplexe const&);

    //! \brief Destructeur de littérale complexe
    ~littcomplexe()
    {
        delete partRe;
        delete partIm;
    }


    //! \brief Getter de la partie réelle
    //! \return    Un \e littNumerique* possédant le contenue de la partie réelle.
    littNumerique* getPartRe() const { return partRe; }
    //! \brief Getter de la partie imaginaire
    //! \return    Un \e littNumerique* possédant le contenue de la partie imaginaire.
    littNumerique* getPartIm() const { return partIm; }

    void simplifier() {}

    bool isNull(){
        if(partRe->isNull()==true){
            if(partIm->isNull()==true){
                return true;
            }else return false;
        }
        else return false;
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
        f.append(" $ ");
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
};

#endif // LITTCOMPLEXE_H
