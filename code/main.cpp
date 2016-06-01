#include "littreelle.h"
#include "littentiere.h"

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


    return 0;
}

