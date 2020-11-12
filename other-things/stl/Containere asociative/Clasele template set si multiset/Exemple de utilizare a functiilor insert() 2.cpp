#include <iostream>
#include <set>
using namespace std;

typedef set<int>::iterator IS;

int main()
{
    set<int> s;
    pair<IS,bool> p;  ///p-obiect de tip pereche

    p=s.insert(2);
    if(p.second==true)
       cout<<*p.first;

    p=s.insert(2);
    if(p.second==true)
       cout<<*p.first;
    else
       cout<<"\nInserare esuata";
    return 0;
}
