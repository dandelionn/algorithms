#include <iostream>
#include <string.h>
using namespace std;
int a[100],n,k,ev,as,v[100],min,max,b[100],c[100],y=1,x=1;
int minandmax()
{
    min=max=v[1];
    for(i=2;i<n;i++)
       if(v[i]<min)
         b[y]=i;
         y++;
       if(v[i]>max)
         c[x]=i;
         x++;
}
void init()
{
    a[k]=-1;
}
int succesor()
{
    if(a[k]<2*n+1)
      {
          a[k]+=2;
          return 1;
      }
    else
          return 0;
}
int valid()
{
    for(int i=1;i<k;i++)
        if(a[k]==a[i])
          return 0;
    return 1;
}
int solutie()
{
    return k==n;
}
void tipar()
{
    for(int i=1;i<y;i++)
        if(a[i]==i)
    for (int i=1;i<=n;i++)
         cout<<v[a[i]];
    cout<<'\n';
}
void bt()
{
    k=1;
    init();
    while(k>0)
        {
            as=1; ev=0;
            while(as && !ev)
                 {
                     as=succesor();
                     if(as)
                       ev=valid();
                 }
            if(as)
               if(solutie())
                  tipar();
               else
                  {
                      k++;
                      init();
                  }
            else
                k--;
        }
}
int main()
{
    cout<<"n=";cin>>n;
    for(int i=1;i<=2*n+1;i++)
       cin>>v[i];
    bt();
}
