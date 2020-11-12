#include <fstream>
#include <queue>
#include <vector>
using namespace std;

ifstream f("bellmanford.in");
ofstream g("bellmanford.out");

struct muchie{int y,c;}el;

vector<muchie> a[50001];
vector<muchie>::iterator it;


#define INF 99999999

int x,n,m,i,D[50001],viz[50001]={0};
bool cn=0,este[50001]={0};
queue<int> qh;

int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
        {f>>x>>el.y>>el.c;
        a[x].push_back(el);}

    D[1]=0;
    for(i=2;i<=n;i++)
        D[i]=INF;
    qh.push(1);

    while(!qh.empty()&&!cn)
    {
        x=qh.front();qh.pop();este[x]=0;
        for(it=a[x].begin();it!=a[x].end();++it)
            if( D[it->y]> D[x] + it->c )
                {
                D[it->y]= D[x] + it->c;

                if(!este[it->y])
                    {qh.push(it->y);
                    este[it->y]=1;}
                viz[it->y]++;

                if(viz[it->y]>n)
                    cn=1;
                }
    }
    if(cn)
        g<<"Ciclu negativ!";
    else
        for(i=2;i<=n;i++)
            g<<D[i]<<' ';

    f.close();g.close();
}
