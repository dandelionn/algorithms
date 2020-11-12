#include <iostream>
using namespace std;

template<typename T>
int F(T t[],T val)
{
    char *p;
    for(p=t;*p!='\0';p++)
        if(*p==val)
           return p-t;
    return -1;
}
int main()
{
    char a[20],val;
    cout<<"sir=";
    cin>>a;
    cout<<"val= ";cin>>val;
    if(F(a,val)>=0)
       cout<<"se gaseste in sir";
    else
       cout<<"nu se gaseste";

}
