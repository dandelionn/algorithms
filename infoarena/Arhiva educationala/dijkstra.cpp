#include <fstream>
#include <queue>
#include <vector>
using namespace std;
ifstream f("dijkstra.in");
ofstream g("dijkstra.out");

struct muchie{int y,c;}el;

vector<muchie> a[50001];
vector<muchie>::iterator it;


#define INF 99999
int x,n,m,i,D[50001];

struct cmp{
   bool operator()(int x,int y) const
            {return D[x]>D[y];}
};

priority_queue<int,vector<int>,cmp> heap;

int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
        {f>>x>>el.y>>el.c;
        a[x].push_back(el);}

    D[1]=0;
    for(i=2;i<=n;i++)
        D[i]=INF;
    heap.push(1);

    while(!heap.empty())
    {
        x=heap.top();heap.pop();
        for(it=a[x].begin();it!=a[x].end();++it)
            if(D[x]+it->c<D[it->y])
                {
                D[it->y]=D[x]+it->c;
                heap.push(it->y);
                }
    }
    for(i=2;i<=n;i++)
        if(D[i]==INF)
          g<<0<<' ';
        else
          g<<D[i]<<' ';
    f.close();g.close();
}
