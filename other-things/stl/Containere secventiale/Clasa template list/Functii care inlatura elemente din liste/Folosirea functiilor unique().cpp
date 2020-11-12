#include <iostream>
#include <list>
using namespace std;

bool Egal(char a,char b)   //predicat binar
{
    return a==b;
}

typedef list<char> LC;
typedef list<char>::iterator IT;

void Scrie(LC L)
{
    for(IT it=L.begin(); it!=L.end(); ++it)
        cout<<*it;
    cout<<'\n';
}
int main()
{
    char s[]="AaAAa! Ahaaaa!";
    LC L(s,s+14);

    L.unique();  ///Elimina repetitiile
    Scrie(L);
    L.assign(s,s+14);

    L.unique(Egal);
    Scrie(L);

    return 0;
}
