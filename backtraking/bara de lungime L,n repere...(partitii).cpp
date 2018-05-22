#include <fstream>
#include <iostream>
using namespace std;
ifstream f("repere.in");
int a[100],s=0,n,as,ev,k,L,b[100],este=0;
void init()
{
    if(k==1)
      a[k]=0;
    else
      a[k]=a[k-1]-1;
}
int succesor()
{
    if(a[k]<n)
      {a[k]=a[k]+1;
      return 1;}
    else
      {s-=b[a[k-1]];
      return 0;}
}
int valid()
{
    if(s+b[a[k]]<=L)
      {s+=b[a[k]];
      return 1;}
    else
       return 0;
}
int solutie()
{
    return L==s;
}
void tipar()
{
    int i,j,p;este=1;
    for(i=1;i<=n;i++)
       {for(j=1,p=0;j<=k;j++)
          if(a[j]==i)
            p++;
       if(p!=0)
         cout<<p<<'*'<<b[i]<<" + ";}
    cout<<'\b'<<'\b'<<' '<<'\n';
    s-=b[a[k]];
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
    f>>n;
    for(int i=1;i<=n;i++)
        f>>b[i];
    f>>L;bt();
    if(!este)
       cout<<"Imposibil";
    f.close();
}
