#include <fstream>

using namespace std;

ifstream f("newyork.in");
ofstream g("newyork.out");

#define Nmax 1001
#define FINIT 50000
int a[Nmax][Nmax],n,m,viz[Nmax],d[Nmax],p[Nmax],v[5];

void init()
{
    int i,j;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
           if(i!=j)
               a[i][j]=FINIT;
           else
               a[i][j]=0;
}

void citire()
{
    int i,x,y,t;
    f>>n>>m;
    init();
    for(i=1;i<=4;i++)
       f>>v[i];
    for(i=1;i<=m;i++)
        {f>>x>>y>>t;
        a[x][y]=t;
        a[y][x]=t;}
    f.close();
}

void dijkstra(int x0)
{
    int i, j, min, k, ok;
    for (i=1;i<=n;i++)
        {
            d[i]=a[x0][i];
            p[i]=x0;
            viz[i]=0;
        }
    p[x0]=0;
    viz[x0]=1;ok=1;
    while (ok)
        {
        min=FINIT;
        for (i=1;i<=n;i++)
            if (!viz[i] && min>d[i])
                {
                    min=d[i];
                    k=i;
                }
        if (min != FINIT)
            {
               viz[k]=1;
               for (i=1;i<=n;i++)
                   if (!viz[i] && d[i]>d[k]+a[k][i])
                      {
                          d[i]=d[k]+a[k][i];
                          p[i]=k;
                      }
            }
        else
            ok = 0;
        }
}

void drum(int x)
{
    int i,h=0,traseu[Nmax];
    while(p[x])
         {
             traseu[++h]=x;
             x=p[x];
         }
    traseu[++h]=x;
    for(i=h;i>=1;i--)
        g<<traseu[i]<<' ';
    g<<'\n';
}
int main()
{
    int i,j;
    citire();
    for(i=1;i<=n;i++)
        {dijkstra(i);
        for(j=1;j<=n;j++)
           {g<<"d["<<n+1-j<<"]="<<d[n+1-j]<<"    ";
           drum(n+1-j);}
        g<<'\n';}
    g.close();
    return 0;
}
