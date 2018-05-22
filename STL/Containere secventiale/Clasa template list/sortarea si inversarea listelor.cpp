#include <iostream>
#include <list>
#include <string>
using namespace std;

bool MaiMare(string s1,string s2)  ///predicat binar
{
    return s1>s2;
}

typedef list<string> LS;
typedef list<string>::iterator IT;

void Scrie(LS L)
{
    for(IT it=L.begin();it!=L.end();++it)
        cout<<*it<<' ';
    cout<<'\n';
}

int main()
{
    string s[]={"asa","se","face"};
    LS L(s,s+3);

    L.sort();   ///"asa" "face" "se"
    Scrie(L);

    L.sort(MaiMare); ///"se" "face" "asa"
    Scrie(L);

    L.reverse();   ///"asa" "face" "se"
    Scrie(L);

    return 0;
}
