#include <iostream>
#include <list>
using namespace std;

int a[]={8,6,4};
int b[]={5,3};

int main()
{
    list<int> L1(a,a+3);
    list<int> L2(b,b+2);

    L1.merge(L2,greater<int>()); ///Ordoneaza descrescator

    list<int>::iterator it;
    for(it=L1.begin();it!=L1.end();++it)
       cout<<*it<<" ";
    return 0;
}
