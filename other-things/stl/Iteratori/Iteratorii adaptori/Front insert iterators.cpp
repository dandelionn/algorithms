#include <iostream>
#include <iterator>
#include <deque>
using namespace std;

int main()
{
    int a[]={1,2,3};
    deque<int> Q;
    deque<int>::iterator it;

    ///Insereaza la inceput 1 2 3,prin apelul constructorului
    copy(a,a+3,front_insert_iterator<deque<int> >(Q) );

    ///Insereaza la inceput 1 2 3, cu funtia front_inserter()
    copy(a,a+3,front_inserter(Q) );

    for(it=Q.begin();it!=Q.end();++it)
       cout<<*it<<' ';
    return 0;
}
