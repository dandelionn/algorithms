#include <vector>
#include <fstream>
using namespace std;

ifstream f("bfs.in");
ofstream g("bfs.out");


#define Nmax 100001
#define pb(x) push_back(x)

vector<int>::iterator it;
vector<int> a[Nmax];

int i,x,y,n,m,s,viz[Nmax]={0},Q[Nmax],val[Nmax]={0};


int main()
{
    f>>n>>m>>s;
    for(i=1;i<=m;i++)
        {f>>x>>y;
        a[x].pb(y);}

    i=0;x=1;
    Q[++i]=s;
    val[s]=0;
    while(i<n&&x<=i)
        {
            s=Q[x];
            if(!viz[s])
               {viz[s]=1;
               for(it=a[s].begin();it!=a[s].end();++it)
                   if(!val[*it]&&!viz[*it])
                      {Q[++i]=*it;
                      val[*it]=val[s]+1;}}
             x++;
        }
    for(i=1;i<=n;i++)
       if(val[i]==0)
          val[i]=-1;
    val[Q[1]]=0;
    for(i=1;i<=n;i++)
       g<<val[i]<<' ';
    f.close();g.close();
}
