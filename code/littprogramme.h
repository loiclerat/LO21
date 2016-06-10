#ifndef LITTPROGRAMME_H
#define LITTPROGRAMME_H

#include "litterale.h"

class littProgramme : public litterale
{
    QString str;
public:
    littProgramme(QString s):str(s){}
    ~littProgramme(){}

    QString affichage(QString f="")const{
        f.append(str);
        return f;
    }

    QString getStr(){
        return str;
    }

    bool isNull(){
        if(str == ""){
            return true;
        }else return false;
    }

};

#endif // LITTPROGRAMME_H
