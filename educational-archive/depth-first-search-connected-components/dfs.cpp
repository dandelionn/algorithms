#include <fstream>
#include <vector>

using namespace std;

ifstream f("dfs.in");
ofstream g("dfs.out");

#define Nmax 100001
#define pb(x) push_back(x)

int i,k,nr,n,m,j,viz[Nmax];

typedef vector<int>::iterator iter;
vector<int> a[Nmax];

void dfs(int i)
{
    iter it;
    for(it=a[i].begin();it!=a[i].end();++it)
        if(!viz[*it])
           {
               viz[*it]=1;
               dfs(*it);
           }
}

int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
       {f>>k>>nr;
       a[k].pb(nr);
       a[nr].pb(k);}
    nr=0;   //nr de componente conexe
    for(i=1;i<=n;i++)
       if(!viz[i])
         {
             if(a[i].empty())
                nr++;
             else
                {viz[i]=1;
                dfs(i);
                nr++;}
         }
    g<<nr;
    f.close();g.close();
}
