#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

ifstream f("apm.in");
ofstream g("apm.out");

struct muchie{int x,y,c;}a[400001];

struct cmp{
    bool operator()(muchie x,muchie y) const
    {return x.c<y.c;}
};

int i,n,m,k,L[200001],ct,x,y;
vector<muchie> v;
vector<muchie>::iterator it;

int rad(int x)            ///cauta radacina subarborelui din care face parte x
{
    if(L[x]!=x)
        L[x]=rad(L[x]);
    return L[x];
}

int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
        f>>a[i].x>>a[i].y>>a[i].c;

    sort(a+1,a+m+1,cmp());

    for(i=1;i<=n;i++)
        L[i]=i;
    k=0;ct=0;                      ///k-nr de muchii alese
    for(i=1;i<=m&&k<n-1;i++)
        {x=rad(a[i].x);
        y=rad(a[i].y);
        if(x!=y)                   ///daca radacinile celor doi subarbori sunt diferite
           {v.push_back(a[i]);
           L[y]=x;                 /// se considera x ca fiind radacina ambilor subarbori
           k++;
           ct+=a[i].c;}

    }
    g<<ct<<'\n'<<n-1<<'\n';
    for(it=v.begin();it!=v.end();++it)
        g<<it->x<<' '<<it->y<<'\n';

    f.close();g.close();
}
