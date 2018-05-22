#include <fstream>
#include <math.h>
using namespace std;

ifstream f("formula.in");
ofstream g("formula.out");

int n=6,y,a[101],semn[3],x[101][3],x0,k,ev,as;

int ecuatie(int e)
{
    int i,s=0;
    for(i=2;i<=n;i+=2)
       s+=a[i-1]*a[i]*pow(e,(n/2-(i/2-1)-1));
    return s;
}

void init()
{
    if(k%2==1)
       a[k]=-3;
    else
       a[k]=-1;
}

int succesor()
{
    if(k%2==1)
       {if(k>1)
          {if(a[k]<1)
            {
                 a[k]+=2;
                 return 1;
            }
          else
             return 0;}
       else
          {if(a[k]<-1)
             {
                 a[k]+=2;
                 return 1;
             }
          else
                 return 0;}}
    else
        if(a[k]<150)
          {
             a[k]++;
             return 1;
          }
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
    int i,poz=0,neg=0,el;
    for(i=1;i<=y;i++)
        {el=ecuatie(x[i][1]);
        if(el==x[i][2])
            poz++;
        if(((-1)*el)==x[i][2])
            neg++;}
    if(poz==y)
        {g<<ecuatie(x0);
        k=-1;}
    else
       if(neg==y)
         {g<<(-1)*ecuatie(x0);
         k=-1;}
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
    int i;
    semn[1]=1;semn[2]=-1;
    f>>y>>x0;
    for(i=1;i<=y;i++)
        f>>x[i][1]>>x[i][2];
    f.close();
    bt();
    g.close();
    return 0;
}
