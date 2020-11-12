#include <iostream>
using namespace std;
int a[100],ev,as,n,m,k;
void init()
{
      if(k==1)
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
    return 1;
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
    cout<<"m=";cin>>m;
    bt();
}
