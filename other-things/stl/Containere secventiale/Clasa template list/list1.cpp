#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<double> L;   ///Construieste o lista vida
    for(int i=0;i<10;++i)
       L.push_back(i);

    while(!L.empty())
    {
        cout<<L.front()<<' ';   ///returneaza primul element
        L.pop_front();          ///sterge primul element
    }
    return 0;
}
