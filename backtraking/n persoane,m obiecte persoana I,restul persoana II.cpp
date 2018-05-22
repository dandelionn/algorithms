#include <iostream>
using namespace std;
int a[100],ev,as,n,m,k,b[100];
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
    int nr,h=1,s=0,s1=0;
    for(int i=1;i<=n;i++)
       {
           nr=0;
           for(int j=1;j<=m;j++)
             if(i==a[j])
               nr++;
           if(nr==0)
             {b[h]=i;
             s+=i;
             h++;}
       }
    for(int i=1;i<=m;i++)
       s1+=a[i];
    if(s==s1)
      {for(int i=1;i<=m;i++)
          cout<<a[i]<<' ';
      cout<<'\n';
      for(int i=1;i<=h-1;i++)
         cout<<b[i]<<' ';
      cout<<'\n'<<'\n';}
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
