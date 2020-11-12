#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

///Clasa de functori
struct Scrie{
    void operator() (int elem) const
    {cout<<elem<<' ';}
};

int main()
{
    deque<int> q;
    ///Insereaza elementele 1 2 3 4 5 in deque
    for(int i=1;i<=5;i++)
         q.push_back(i);

    ///Foloseste reverse_iterator-i pentru parcurgere
    for_each(q.rbegin(), q.rend(), Scrie());

    ///Cauta valoarea 3 si returneaza in it pozitia sa
    deque<int>::iterator it=find(q.begin(),q.end(),3);

    ///converteste it la reverse_iterator
    deque<int>::reverse_iterator rit(it);   ///Constructor

    cout<<'\n'<<*rit<<'\n';

    ///converteste rit la iterator
    it=rit.base();
    cout<<*it;

    return 0;
}
