#include <iostream>
#include <math.h>
using namespace std;
int a[100],n,k,ev,as;
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
    for(int i=1;i<=n;i++)
       cout<<a[i]<<' ';
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
    bt();
}


