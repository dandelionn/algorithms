#include <iostream>
using namespace std;
int a[100],ev,as,k,n,m,q=1;
void init()
{
    a[k]=-1;
}
int succesor()
{
    if(a[k]<1)
      {a[k]+=1;
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
    return k==q;
}
void tipar()
{
    int ok=1;
    for(int i=1;i<=k;i++)
       if(a[i]==0)
         ok=0;
    for(int i=1;i<=k;i++)
        cout<<a[i];
    cout<<'\n';
    if(ok&&q<m+n-1)
       {for(int i=1;i<=q;i++)
          a[i]=-1;
       k=1;
       q++;}
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
    cout<<"m=";cin>>m;
    cout<<"n=";cin>>n;
    bt();
}
