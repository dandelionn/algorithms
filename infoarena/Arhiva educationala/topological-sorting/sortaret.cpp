#include <vector>
#include <fstream>
using namespace std;

ifstream f("sortaret.in");
ofstream g("sortaret.out");
#define Nmax  50001
#define pb(x) push_back(x);

vector<int>::iterator it;
vector<int> a[Nmax];
int i,j=0,x,y,n,m,ex[Nmax]={0},Q[Nmax];

int main()
{

    f>>n>>m;
    for(i=1;i<=m;i++)
       {f>>x>>y; a[x].pb(y);
       ex[y]++;}

    for(i=1;i<=n;i++)
       if(ex[i]==0)
          Q[++j]=i;


    for(i=1;i<=n;i++)
        {x=Q[i];
        for(it=a[x].begin();it!=a[x].end();++it)
            if(ex[*it]==1)
               Q[++j]=*it;
            else
               ex[*it]--;}

    for(i=1;i<=n;i++)
        g<<Q[i]<<' ';

    f.close();g.close();
    return 0;
}
