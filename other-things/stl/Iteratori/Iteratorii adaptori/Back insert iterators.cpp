#include <iterator>
#include <list>
#include <iostream>
using namespace std;

int main()
{
    int a[]={1,2,3};
    list<int> L;  /// lista vida
    list<int>::iterator i;

    ///Construieste obiectul it de tip back_insert_iterator
    back_insert_iterator<list<int> > it(L);

    *it=10;  ///Apeleaza list<int>::push_back(10);
    it++;    ///Fara efect
    *it=20;  ///Apeleaza list<int>::push_back(20);
    ++it;    ///Fara efect
    it=30;   ///Acelasi efect cu *it=30

    ///Insereaza valorile 1,2,3, folosind iteratorul it
    copy(a,a+3,it);

    for(i=L.begin();i!=L.end();++i)
       cout<<*i<<' ';

    return 0;
}
