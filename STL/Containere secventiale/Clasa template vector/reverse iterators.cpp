#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    for(int i=0;i<10;i++)
       v.push_back(i);
    vector<int>::reverse_iterator rit;

    ///Traversare de la sfarsit catre inceputul secventei
    for(rit=v.rbegin();rit!=v.rend();++rit)
        cout<<*rit<<' ';
    return 0;
}
