#include <iostream>
#include <string.h>
using namespace std;
int a[100],n,k,ev,as,v[100];
void init()
{
    a[k]=0;
}
int succesor()
{
    if(a[k]<n)
      {
          a[k]++;
          return 1;
      }
    else
          return 0;
}
int valid()
{
    if(k>1&&(v[a[k-1]]%2==0&&v[a[k]]%2==0)||(v[a[k-1]]%2==1&&v[a[k]]%2==1))
           return 0;
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
    for(int i=1;i<=n;i++)
       cin>>v[i];
    bt();
}
