#include "littreelle.h"
#include "littentiere.h"
#include "littrat.h"
#include "add.h"

using namespace std;
int main(){
    littEntiere l(6);
    littEntiere m(5);
    (l+m).affichage();
    littEntiere n=l;

    cout<<"\n****************\n";
    n=m+l;
    n.affichage();
    cout<<"\n****************\n";
    n.NEG();
    n.affichage();
    cout<<"\n****************\n";
    n=m-l;
    n.affichage();
    cout<<"\n****************\n";
    n=m*l;
    n.affichage();
    cout<<"\n****************\n";

    littReelle r(8,0.25);
    littReelle j(0.93);
    littReelle i=j;

    cout<<"\n****************\n";
    cout<<j.getValeur()<<"\n";
    cout<<j.getEntiere()<<"\n";
    cout<<j.getDecimale()<<"\n";
    cout<<"\n****************\n";
    cout<<(j+r).getDecimale()<<"\n";
    cout<<"\n****************\n";
    cout<<(j-r).getDecimale()<<"\n";
    (r*j).affichage();
    cout<<"\n****************\n";
    try{
        littReelle b(0);
        littReelle a(8);
    }
    catch(Exception e){
        cout<<e.getInfo();
        if(e.getInfo()=="entier")
            littEntiere b(0);
    }
    //b.affichage();

    littrat rat1(1,3);
    littrat rat2(3,4);


    return 0;
}

/*
#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>

#include "qcomputer.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    QComputer fenetre;
    fenetre.show();
    return app.exec();

}*/
