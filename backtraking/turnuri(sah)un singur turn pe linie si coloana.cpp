#include <iostream>
#include <string.h>
using namespace std;
int a[100],n,k,ev,as;
bool v[100][100];
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
    for (int i=1;i<=n;i++)
       {v[i][a[i]]=1;
        for (int j=1;j<=n;j++)
         cout<<v[i][j]<<' ';
       cout<<'\n';}
    cout<<'\n';
    for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
          v[i][j]=0;
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
