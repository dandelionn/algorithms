#include <fstream>
using namespace std;
ifstream f("dijkstra.in");
ofstream g("dijkstra.out");
#define Nmax 8000
int a[Nmax][Nmax],n,m,s[Nmax]={0},d[Nmax],p[Nmax];
int const val=1000001;

void init()
{
    int i,j;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
           if(i!=j)
               a[i][j]=val;
           else
               a[i][j]=0;
}

void generare_drum()
{
    int i,j,min,y;s[1]=1;
    for(i=1;i<=n;i++)
        {d[i]=a[1][i];
        if(d[i]!=val)
           p[i]=1;
        else
           p[i]=0;}
    for(i=1;i<=n-1;i++)
        {for(j=1,min=val;j<=n;j++)
           if(s[j]==0&&d[j]<min)
              {min=d[j];
              y=j;}
        s[y]=1;
        for(j=1;j<=n;j++)
           if(s[j]==0&&d[j]>d[y]+a[y][j])
               {d[j]=d[y]+a[y][j];
               p[j]=y;}}
}
void afisare()
{
    for(int i=2;i<=n;i++)
        g<<d[i]<<' ';
}
int main()
{
    int x,y,c,i;
    f>>n>>m;
    init();
    for(i=1;i<=m;i++)
       {f>>x>>y>>c;
       a[x][y]=c;}
    generare_drum();
    afisare();
    g.close();
    f.close();
}
