#include <iostream>
#include <list>
using namespace std;

int a[]={2,4,6};
int b[]={3,5};

int main()
{
    list<int> L1(a,a+3);
    list<int> L2(b,b+2);

    L1.merge(L2);   ///Interclaseaza L1 cu L2

    list<int>::iterator it;
    for(it=L1.begin();it!=L1.end();++it)
        cout<<*it<<' ';

    return 0;
}
