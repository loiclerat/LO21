#include "littreelle.h"
#include"littentiere.h"

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

    littReelle r(8,0.25);
    littReelle j(0.93);
    littReelle i=j;

    cout<<"\n****************\n";
    cout<<j.getValeur()<<"\n";
    cout<<j.getEntiere()<<"\n";
    cout<<j.getDecimale()<<"\n";
    cout<<"\n****************\n";
    cout<<(j+r).getDecimale()<<"\n";


    return 0;
}

