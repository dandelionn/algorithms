#include <iostream>
using namespace std;
int i,n,a[50],j,z,b[50];
int citire()
{
    cout<<"n=";
    cin>>n;
    return n;
}
int par(int n)
{
    if(n%2==0)
      return 1;
    else
      return 0;
}
void afisarepare()
{
    for(j=0;j<i;j++)
       if(par(a[j]))
          cout<<a[j];
       else
          {b[z]=a[j];
          z++;}
}
void afisareimpare()
{
    for(j=0;j<z;j++)
       cout<<b[j];
}
int main()
{
    while(citire())
      {a[i]=n;
      i++;}
    afisarepare();
    cout<<'\n';
    afisareimpare();
}
