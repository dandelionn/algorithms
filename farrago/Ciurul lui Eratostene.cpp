#include <iostream>
#include <math.h>
using namespace std;
bool a[2000000];
int nr=0,i,j,n;
int main()
{
    cout<<"n=";cin>>n;
    for(i=2;i<=n;i++)
       a[i]=1;
    cout<<"numere eliminate:"<<'\n';
    for(i=2;i<=sqrt(n);i++)
       if(a[i])
         for(j=i;j<=n/i;j++)
            {a[i*j]=0;
            cout<<i*j<<' ';}
    cout<<'\n';
    for(i=2;i<=n;i++)
       if(a[i])
         nr++;
    cout<<"nr="<<nr;
}
