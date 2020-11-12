#include <set>
#include <iostream>
using namespace std;

//Clasa de functori - stabileste criteriul de ordonare
struct Comp {
    bool operator()(char x,char y) const
    {return x>y; }   ///Ordonare descrescatoare dupa
                     ///codul ASCII
};

int main()
{
    char a[]="anemone";
    multiset<char, Comp> s(a,a+7);

    multiset<char, Comp>::iterator it;
    for(it=s.begin();it!=s.end();++it)
        cout<<*it;

    return 0;
}
