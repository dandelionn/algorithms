#include <fstream>
#include <queue>
#include <vector>
using namespace std;

ifstream f("dijkstra.in");
ofstream g("dijkstra.out");

struct muchie{int y,c;}el;

vector<muchie> a[50001];
vector<muchie>::iterator it;


#define INF 99999999

int x,n,m,i,D[50001];
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

    while(!qh.empty())
    {
        x=qh.front();qh.pop();
        for(it=a[x].begin();it!=a[x].end();++it)
            if( D[it->y]> D[x] + it->c )
                {
                D[it->y]= D[x] + it->c;
                qh.push(it->y);
                }
    }

    for(i=2;i<=n;i++)
        if(D[i]==INF)
           g<<0<<' ';
        else
           g<<D[i]<<' ';

    f.close();g.close();
}
