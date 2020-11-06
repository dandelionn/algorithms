#include <fstream>
using namespace std;

ifstream f("rmq.in");
ofstream g("rmq.out");


int i,j,v[100001],n,m,a[10001][10001],el_min,x,y;

int main()
{
    f>>n>>m;
   for(i=1;i<=n;i++)
       f>>v[i];
    for(i=1;i<=n;i++)
       {el_min=100000;
       for(j=i;j<=n;j++)
          {if(v[j]<el_min)
             el_min=v[j];
          a[i][j]=el_min;}}
     for(i=1;i<=m;i++)
        {f>>x>>y;
        g<<a[x][y]<<'\n';}
     f.close();
     g.close();
}
