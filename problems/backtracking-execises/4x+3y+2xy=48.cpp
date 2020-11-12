#include <iostream>
using namespace std;
int a[100],ev,as,k,n;
void init()
{
    a[k]=-1;
}
int succesor()
{
    if(a[k]<16)
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
    return k==2;
}
void tipar()
{
     if((4*a[k-1]+3*a[k]+2*a[k-1]*a[k])==48)
        cout<<a[k-1]<<' '<<a[k]<<'\n';
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
    bt();
}
