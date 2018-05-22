#include <iostream>
#include <list>
#include <cstring>
using namespace std;

const char voc[]="AaEeIiOoUu";
bool Vocala(char c)   ///Predicat unar
{
    return strchr(voc,c);
}

typedef list<char> LC;
typedef list<char>::iterator IT;

void Scrie(LC L)
{
    for(IT it=L.begin();it!=L.end(); ++it)
        cout<<*it;
}

int main()
{
    char s[]="unu Doi Trei";
    LC L(s,s+12);

    L.remove('u');
    Scrie(L);
    cout<<'\n';

    L.remove_if(Vocala);
    Scrie(L);

    return 0;
}
