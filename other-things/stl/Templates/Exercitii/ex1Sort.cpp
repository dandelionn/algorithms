#include <iostream>
using namespace std;

template<typename T,int n>
void F(T t[])
{
    int i,j;
    T aux;
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
            if(t[i]>t[j])
               {aux=t[i];
               t[i]=t[j];
               t[j]=aux;}
}

int main()
{
    int t[100];
    const int n=5;
    for(int i=1;i<=n;i++)
        cin>>t[i];
    F<int,n>(t);
    for(int i=1;i<=n;i++)
       cout<<t[i]<<' ';
    return 0;
}
