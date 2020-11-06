#include <algorithm>
#include <fstream>
using namespace std;

ifstream f("arbint.in");
ofstream g("arbint.out");

int arb[400005],n,m,a,b,ct,nod,el_max=-10000;

void update(int nod,int st,int dr)
{
    if(st==dr)
       arb[nod]=b;
    else
       {int mij=(st+dr)/2;
       if(a<=mij)
          update(nod*2,st,mij);
       else
          update(nod*2+1,mij+1,dr);
       arb[nod]=max(arb[nod*2],arb[nod*2+1]);}
}

void query(int nod,int st,int dr)
{
    if( a<=st && dr<=b )
       {if(arb[nod]>el_max)
          el_max=arb[nod];}
    else
       {int mij=(st+dr)/2;
        if(a<=mij)
           query(nod*2,st,mij);
        if(b>mij)
           query(nod*2+1,mij+1,dr);}
}

int main()
{
    int i;

    f>>n>>m;

    for(i=1;i<=n;i++)
        {f>>b;  //valoare
        a=i;  //pozitie
        update(1,1,n);}
    for(i=1;i<=m;i++)
        {f>>ct;
        if(ct==0)
           {el_max=-10000;
           f>>a>>b;
           query(1,1,n);
           g<<el_max<<'\n';}
        else
           if(ct==1)
              {f>>a>>b;
              update(1,1,n);}}

     f.close();
     g.close();
     return 0;
}
