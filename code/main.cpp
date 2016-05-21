
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
    cout<<"\n";

    return 0;
}

