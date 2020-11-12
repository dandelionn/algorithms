#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("demolish.in");
ofstream g("demolish.out");

int arb[100000],n,m,a,b,el_max;

void update(int nod,int st,int dr)
{
    if(st==dr)
       arb[nod]=b;
    else
        {int mij=st+(dr-st)/2;
        if(a<=mij)
            update(nod*2,st,mij);
        else
            update(nod*2+1,mij+1,dr);
        arb[nod]=max(arb[nod*2],arb[nod*2+1]);}
}
void query(int nod,int st,int dr)
{
    if(a<=st&&dr<=b)
        {if(arb[nod]>el_max)
           el_max=arb[nod];}
    else
        {int mij=st+(dr-st)/2;
        if(a<=mij)
            query(nod*2,st,mij);
        if(b>mij)
            query(nod*2+1,mij+1,dr);}
}

int main()
{
    int ct;
    f>>n>>m;
    for(int i=1;i<=n;i++)
       {f>>b;
       a=i;
       update(1,1,n);}
    for(int i=1;i<=m;i++)
       {f>>ct;
       if(ct==0)
           {f>>a>>b;
           el_max=-10000;
           query(1,1,n);
           g<<el_max<<'\n';}
       else
            {f>>a>>b;
            update(1,1,n);}
       }
  f.close();g.close();
  return 0;
}
