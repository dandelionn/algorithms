#include <fstream>

using namespace std;

ifstream f("bellmanford.in");
ofstream g("bellmanford.out");

struct muchie{ int x,y,c;}a[250001];

#define INF 5000000

int n,m,D[50001],i,j,x;
bool ciclunegativ=0;

int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
        f>>a[i].x>>a[i].y>>a[i].c;

    D[1]=0;
    for(i=2;i<=n;i++)
        D[i]=INF;


    for(i=1;i<n;i++)
        for(j=1;j<=m;j++)
            if(  D[a[j].x]   +    a[j].c   <   D[a[j].y]  )
                 D[a[j].y]   =    D[a[j].x] +  a[j].c;

    for(j=1;j<=m;j++)
        if(  D[a[j].x]   +    a[j].c   <   D[a[j].y]  )
            ciclunegativ=1;
    if(ciclunegativ)
       g<<"Ciclu negativ!";
    else
       for(i=2;i<=n;i++)
           g<<D[i]<<' ';

    f.close();g.close();
}
