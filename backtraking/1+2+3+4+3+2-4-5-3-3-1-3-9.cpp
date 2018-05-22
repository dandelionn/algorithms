#include <iostream>
using namespace std;
int a[100],ev,as,k,n,m[100];
void init()
{
    a[k]=0;
}
int succesor()
{
    if(a[k]<2)
      {a[k]++;
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
    return k==n-1;
}
void tipar()
{ int ok=0;
    for(int i=1;i<n;i++)
       if(a[i]==1&&m[i]<=m[i+1])
          ok=1;
    if(ok==0)
      {for(int i=1;i<n;i++)
         if(a[i]==1)
            cout<<m[i]<<'-';
         else
            cout<<m[i]<<'+';
      cout<<m[n]<<'\n';}
}
void bt()
{
    k=1;
    init();
    while(k>0)
        {
            as=1;ev=0;
            while(as &&!ev )
                 {as=succesor();
                 if(as)
                   ev=valid();}
            if(as)
              {
                  if(solutie())
                    tipar();
                  else
                    {k++;
                    init();}
              }
            else
               k--;
        }
}
int main()
{
    cout<<"n=";cin>>n;
    for(int i=1;i<=n;i++)
       cin>>m[i];
    bt();
}
