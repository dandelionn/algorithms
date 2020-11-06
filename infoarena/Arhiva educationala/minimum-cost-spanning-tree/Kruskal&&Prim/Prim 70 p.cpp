#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream f("apm.in");
ofstream g("apm.out");

struct muchie{int x,y,c;}a[400001];
struct cmp{
    bool operator()(muchie a,muchie b) const
       {return a.c<b.c;};
};

vector<muchie> v;
vector<muchie>::iterator it;

int n,m,k,i,ct;
bool L[200001];

int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
        f>>a[i].x>>a[i].y>>a[i].c;

    sort(a+1,a+m+1,cmp());

    for(i=1;i<=n;i++)
        L[i]=0;
    L[1]=1;
    k=ct=0;i=1;
    while(k<n-1)
        {while(L[a[i].x]==L[a[i].y])
               i++;
         k++;
         ct+=a[i].c;
         v.push_back(a[i]);

         L[a[i].x]=L[a[i].y]=1;
         i=1;}

    g<<ct<<'\n'<<n-1<<'\n';
    for(it=v.begin();it!=v.end();++it)
        g<<it->x<<' '<<it->y<<'\n';

    f.close(); g.close();
}
