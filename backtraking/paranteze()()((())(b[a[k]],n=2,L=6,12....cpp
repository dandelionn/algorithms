#include <iostream>
using namespace std;
int a[100],s=0,n,as,ev,k,L,b[100],sum=0;
int parant()
{
    int i=1,nr=0;
    if(a[i]!=1||k%2==1)
      return 0;
    nr=0;
    i=1;
    while(i<=k)
        {

            if(a[i]==1)
              nr++;
            if(a[i]==2)
              {nr--;
              if(nr<0)
                return 0;}
            i++;
        }
    if(nr==0)
      return 1;
    else
      return 0;
}
void init()
{
      a[k]=0;
}
int succesor()
{
    if(a[k]<n)
      {a[k]++;
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
    int i;
    if(parant())
      {for(i=1;i<=k;i++)
          cout<<b[a[i]]<<' ';
      cout<<'\n';}
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
    cout<<"n=";cin>>n;
    cout<<"L=";cin>>L;
    for(int i=1;i<=n;i++)
        cin>>b[i];
    bt();
}
