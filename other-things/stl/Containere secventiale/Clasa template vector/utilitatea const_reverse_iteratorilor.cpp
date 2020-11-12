#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    for(int i=0;i<10;i++)
        v.push_back(i);

    ///Se construieste v1 prin copiere din v
    const vector<int> v1(v);

    ///v1 este constant; necesita un const_reverse_iterator
    vector<int>::const_reverse_iterator rit;

    ///Traversare de la sfarsit catre inceputul secventei
    for(rit=v1.rbegin();rit!=v1.rend();++rit)
         cout<<*rit<<' ';

    return 0;
}
