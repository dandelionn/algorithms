#include <iostream>
using namespace std;
int a[100],ev,as,n,m,k,p,q;
void init()
{
    if(k==2)
      a[k]=0;
    else
      a[k]=a[k-1];
}
int succesor()
{
    if(a[k]<n-m+k)
      {a[k]=a[k]+1;
      return 1;}
    else
      return 0;
}
int valid()
{
    return a[k]!=p&&a[k]!=q;
}
int solutie()
{
    return k==m;
}
void tipar()
{
    for(int i=1;i<=m;i++)
       cout<<a[i]<<' ';
    cout<<'\n';
}
void bt()
{
    k=2;
    init();
    while(k>1)
         {
             as=1;ev=0;
             while(as&&!ev)
                  {
                      as=succesor();
                      if(as)
                        ev=valid();
                  }
             if(as)
                if(solutie())
                      tipar();
                else
                    {k++;
                    init();}
             else
                k--;
         }
}
int main()
{
    cout<<"n=";cin>>n;
    cout<<"m=";cin>>m;
    cout<<"p=";cin>>p;
    cout<<"q=";cin>>q;
    a[1]=p;
    bt();
}
