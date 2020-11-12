#include <iostream>
using namespace std;
int a[100],as,ev,n,k,m,b[100];
void init()
{
    a[k]=0;
}
int succesor()
{
    if(a[k]<a[k-1]+1)
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
    int j,i,max=a[1];
    for(i=2;i<=n;i++)
       if(a[i]>max)
         max=a[i];
    for(i=1;i<=max;i++)
         {cout<<"{";
         for(j=1;j<=n;j++)
            {if(a[j]==i)
            cout<<j<<",";}
         cout<<'\b'<<"} ";}
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
