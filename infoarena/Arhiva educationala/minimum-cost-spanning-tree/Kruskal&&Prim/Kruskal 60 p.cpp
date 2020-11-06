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

int i,n,m,k,j,L[200001],ct,el_min,el_max;
vector<muchie> v;
vector<muchie>::iterator it;

int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
        f>>a[i].x>>a[i].y>>a[i].c;

    sort(a+1,a+m+1,cmp());

    for(i=1;i<=n;i++)
        L[i]=i;
    k=0;ct=0;i=1;
    while(k<n-1)     ///n-1 muchii
    {
        if(L[a[i].x]!=L[a[i].y])
            {k++;
            ct+=a[i].c;
            v.push_back(a[i]);

            el_min=min(L[a[i].x],L[a[i].y]);
            el_max=max(L[a[i].x],L[a[i].y]);

            for(j=1;j<=n;j++)
                if(L[j]==el_max)
                   L[j]=el_min;
            i=1;}
        else
           i++;
    }
    g<<ct<<'\n'<<n-1<<'\n';
    for(it=v.begin();it!=v.end();++it)
        g<<it->x<<' '<<it->y<<'\n';

    f.close();g.close();
}
