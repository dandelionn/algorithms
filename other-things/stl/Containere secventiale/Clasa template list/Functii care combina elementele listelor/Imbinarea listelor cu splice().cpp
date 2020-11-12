#include <iostream>
#include <list>
#include <cassert>
using namespace std;

typedef list<char> LC;
typedef LC::iterator ITC;

void Afiseaza(LC L)
{
    for(ITC it=L.begin();it!=L.end();++it)
       cout<<*it;
    cout<<'\n';
}

int main()
{
    char a[]="ABC";

    LC x(a,a+3);
    LC L;     ///Creeaza o lista vida

    ///Muta secventa controlata de x in L
    L.splice(L.begin(),x);
    assert(x.empty());
    Afiseaza(L);

    ///Muta primul caracter din L inainte de sfarsit in x
    x.splice(x.end(),L,L.begin());
    Afiseaza(x);
    Afiseaza(L);

    ///Muta intervalul [L.begin(),L.end()) la inceputul lui x
    x.splice(x.begin(),L,L.begin(),L.end());
    Afiseaza(x);
    assert(L.empty());

    return 0;
}
