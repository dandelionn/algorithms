#include <iostream>
using namespace std;
int a[100],ev,as,n,m,k;
void init()
{
      a[k]=-1;
}
int succesor()
{
    if(a[k]<1)
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
    return k==n;
}
void tipar()
{
    int y=0;
    for(int i=1;i<=n;i++)
       if(a[i]==0)
         y+=1;
    if(y==m)
      {for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
      cout<<'\n';}
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
    a[1]=1;
    bt();
}
