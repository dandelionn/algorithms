#include <iostream>
using namespace std;
int a[100],s=0,n,as,ev,k;
int good()
{
    int ok=0;
    for(int i=1;i<=k;i++)
       if(a[i]==3||a[i]==5)
         ok++;
    return k-ok;
}
void init()
{
    if(k==1)
      a[k]=1;
    else
      a[k]=a[k-1]-1;
}
int succesor()
{
    if(a[k]<n-s)
      {a[k]+=1;
      return 1;}
    else
      s-=a[k-1];
      return 0;
}
int valid()
{
    if(s+a[k]<=n)
      {s+=a[k];
      return 1;}
    else
       return 0;
}
int solutie()
{
    return s==n;
}
void tipar()
{
    if(!good())
      {for(int i=1;i<=k;i++)
           cout<<a[i]<<' ';
      cout<<'\n';}
    s-=a[k];
}
void bt()
{
    k=1;
    init();
    while(k>0)
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
    bt();
}
