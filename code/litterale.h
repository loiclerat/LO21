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


using namespace std;

class litterale{
public :
    litterale(){}
    virtual ~litterale(){}

    virtual QString& affichage(QString f="")const=0;//a definir
    virtual void simplifier(){}/*permet de simplifier les litt num
    *d�s leur cr�ation, �ventuellement les transformer en une autre litt num
    *si possible.
    */
};

// A BOUGER !
class Exception {
    string info;
public:
    Exception(const string& str):info(str){}
    string getInfo() const { return info; }
};

#endif // LITTERALE_H
