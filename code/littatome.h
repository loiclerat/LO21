#ifndef LITTATOME_H
#define LITTATOME_H
#include <QString>

class littatome
{
    QString identificateur; //qui vaut le typeid.name() de ce que l'on cherche � mettre l�  dedans
public:
    littatome(QString i):identificateur(i){}
};

#endif // LITTATOME_H
