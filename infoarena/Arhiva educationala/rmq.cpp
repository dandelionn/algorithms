#include <fstream>

using namespace std;

ifstream f("rmq.in");
ofstream g("rmq.out");

int n,m,a[20][100001],i,j,x,y,k,lg[100001];

int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[0][i];
    for(i=2;i<=n;i++)
        lg[i]=lg[i/2]+1;

    for(i=1;(1<<i)<=n;i++)
        for(j=1;j<=n-(1<<i)+1;j++)
            a[i][j]=min(a[i-1][j],a[i-1][j+(1<<(i-1))]);



    for(i=1;i<=m;i++)
        {f>>x>>y;
        k=lg[y-x+1];
        g<<min(a[k][x],a[k][y-(1<<k)+1])<<'\n';}

    f.close();g.close();
}
