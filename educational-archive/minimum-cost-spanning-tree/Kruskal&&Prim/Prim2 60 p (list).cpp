#include <fstream>
#include <list>
#include <algorithm>

using namespace std;

ifstream f("apm.in");
ofstream g("apm.out");

struct muchie{int x,y,c;}el;
struct cmp{
    bool operator()(muchie a,muchie b) const
       {return a.c<b.c;};
};

list<muchie> lista,v;
list<muchie>::iterator it;

int n,m,k,i,ct;
bool L[200001];

int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
        {f>>el.x>>el.y>>el.c;
        lista.push_back(el);}

    lista.sort(cmp());

    for(i=1;i<=n;i++)
        L[i]=0;
    L[1]=1;
    k=ct=0;i=1;
    it=lista.begin();
    while(k<n-1)
        {while(L[it->x]==L[it->y])
               ++it;
         k++;
         ct+=it->c;
         el.x=it->x; el.y=it->y; el.c=it->c;
         v.push_back(el);

         L[it->x]=L[it->y]=1;

         lista.erase(it);
         it=lista.begin();}

    g<<ct<<'\n'<<n-1<<'\n';
    for(it=v.begin();it!=v.end();++it)
        g<<it->x<<' '<<it->y<<'\n';

    f.close(); g.close();
}
