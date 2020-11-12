#include <iostream>
#include <map>
using namespace std;

int main()
{
    ///Creeaza un sir de obiecte de tip pereche
    pair<int,char> p[]={make_pair(2,'A'),
                       make_pair(3,'B'),
                       make_pair(1,'C')};

    ///Construieste un map cu numele m.Insereaza in acesta
    ///copii ale elementelor din intervalul [p,p+3).
    map<int,char> m(p,p+3);

    map<int,char>::iterator it;
    ///Parcurge containerul afisand cheile si valorile.
    for(it=m.begin();it!=m.end();++it)
        cout<<it->first<<"  "<<it->second<<'\n';

    return 0;
}
