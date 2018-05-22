#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int main()
{
    vector<char> v(5,'W');
    assert(v.size()==5&&v[0]=='W');

    char s[]="Imi place STL!";

    v.assign(s,s+15); ///Inlocuieste secventa controlata
                      ///de v, cu secventa [s,s+15)
    assert(v.size()==15&&v[0]=='I');

    v.assign(10,'Y');  ///Inlocuieste secventa controlata
                       ///de v,cu 10 elem de valoare 'Y'
    assert(v.size()==10&&v[0]=='Y');

    return 0;
}
