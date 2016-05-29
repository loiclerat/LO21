#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <QString>

class ComputerException {
    QString info;
public:
    ComputerException(const QString& str):info(str){}
    QString getInfo() const { return info; }
};

#endif // EXCEPTIONS_H
