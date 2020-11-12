#include <iostream>
using namespace std;
int a[100],ev,as,k,n;
void init()
{
    a[k]=-1;
}
int succesor()
{
    if(a[k]<1)
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
    return k==n;
}
void tipar()
{
    int i,x=0;cout<<"{";
    for(int i=1;i<=n;i++)
       if(a[i]==1)
          {cout<<i<<',';x=1;}
    if(x)
      cout<<'\b';
    cout<<'}'<<'\n';
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
    bt();
}
