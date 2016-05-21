#ifndef LITTERALE_H
#define LITTERALE_H

#include <QString>
#include <QTextStream>
#include <QObject>
#include <QDebug>

using namespace std;


class Exception {
    QString info;
public:
    Exception(const QString& str):info(str){}
    QString getInfo() const { return info; }
};

#endif // LITTERALE_H
