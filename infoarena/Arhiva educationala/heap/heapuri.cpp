#include <fstream>
#include <algorithm>
using namespace std;

ifstream f("heapuri.in");
ofstream g("heapuri.out");

#define Nmax 200001

struct tablou{int el,nr;}H[Nmax];
int n,k=0,ord[Nmax];

void inserare(int x)
{
    k++;
    int i;
    H[++n].el=x;H[n].nr=k;
    ord[k]=n;i=n;
    while(H[i].el<H[i/2].el)
    {
        swap(ord[H[i].nr],ord[H[i/2].nr]);
        swap(H[i],H[i/2]);
        i=i/2;
    }
}
int minim(int x)
{
    if(H[x*2].el<=H[x*2+1].el)
       return x*2;
    else
       return x*2+1;
}
void stergere(int x)
{
    x=ord[x];
    int kmin;
    H[x]=H[n];
    ord[H[x].nr]=x;
    n--;
    while(x*2<=n)
    {
        if(x*2+1>n)
            kmin=x*2;
        else
            kmin=minim(x);
        if(H[x].el>H[kmin].el)
           {swap(ord[H[x].nr],ord[H[kmin].nr]);
           swap(H[x],H[kmin]);
           x=kmin;}
        else
            x=n+1;
    }
}

int main()
{
    int N,i,ct,x;
    f>>N;
    for(i=1;i<=N;i++)
        {f>>ct;
        if(ct==1)
            {f>>x;
            inserare(x);}
        else
            if(ct==2)
               {f>>x;
               stergere(x);}
            else
               g<<H[1].el<<'\n';}
    f.close();
    g.close();
}
