#include <fstream>
using namespace std;
ifstream f("grafxy.in");
ofstream g("grafxy.out");
const int val=5000;
int a[101][101],n,m,ny,nx,x[101],y[101];
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
void transformare()
{
    int k,i,j;
    for(k=1;k<=n;k++)
       for(i=1;i<=n-1;i++)
           for(j=i+1;j<=n;j++)
              if(a[i][k]&&a[k][j]&&(a[i][j]>a[i][k]+a[k][j]||!a[i][j])&&i!=j)
                       {a[i][j]=a[i][k]+a[k][j];
                       a[j][i]=a[i][j];}
}
void distanta()
{
    int i,j,q;
    for(i=1;i<=nx;i++)
       {q=1001;
       for(j=1;j<=ny;j++)
          if(a[x[i]][y[j]]<q)
              q=a[i][y[j]];
       g<<q<<'\n';}
}
int main()
{
    int i,j,k;
    f>>n>>m;
    init();
    for(k=1;k<=m;k++)
        {
            f>>i>>j;
            a[i][j]=1;
            a[j][i]=1;
        }
    transformare();
    f>>nx;
    for(i=1;i<=nx;i++)
       f>>x[i];
    f>>ny;
    for(i=1;i<=ny;i++)
       f>>y[i];
    distanta();
    f.close();
    g.close();
}
