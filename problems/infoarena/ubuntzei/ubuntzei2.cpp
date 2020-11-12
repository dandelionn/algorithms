#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("ubuntzei.in");
ofstream g("ubuntzei.out");
#define INF 5000000
#define NMAX 2001
int n,m,k,a[NMAX][NMAX],c[NMAX],x,y,z,s=50000,v[NMAX];

void test(int v[],int n)
{
    int s1=0;
    for(int i=1;i<=n;i++)
        s1+=a[v[i]][v[i+1]];
    if(s1<s)
       s=s1;
}
void reverse(int a[],int i,int n)
{
    while(i<n)
        {swap(a[i],a[n]);
        i++;n--;}
}
void write(int a[],int n)
{
   for(int i=1;i<=n;i++)
          g<<a[i]<<' ';
   g<<'\n';
}
void next_per(int a[],int n)
{
    test(a,n);
    int i,j;
    i=n-1;j=n;
    while(i>1&&a[i]>a[i+1])
          i--;
    if(i!=1)
       {while(a[j]<a[i]&&j>1)
           j--;
       swap(a[i],a[j]);
       reverse(a,i+1,n);
       next_per(a,n);}
}


void init1()
{
    int i,j;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
         if(i==j)
            a[i][j]=0;
         else
            a[i][j]=INF;
}
void citeste()
{
    int i;
    f>>n>>m>>k;
    for(i=1;i<=k;i++)
       f>>c[i];
    for(i=1;i<=m;i++)
        {f>>x>>y>>z;
        a[x][y]=z;
        a[y][x]=z;}
    f.close();
}
void transforma()
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
           for(j=1;j<=n;j++)
               if(a[i][k]&&a[k][j]&&((a[i][k]+a[k][j]<a[i][j])||!a[i][j])&&i!=j)
                    a[i][j]=a[i][k]+a[k][j];
}
int main()
{
    int i;
    init1();
    citeste();
    transforma();
    x=1;y=n;
    z=k+2;
    v[1]=x;
    for(i=1;i<=k;i++)
       v[i+1]=c[i];
    v[k+2]=y;
    if(k>0)
        next_per(v,k+1);
    else
        s=a[1][n];
    g<<s;
    g.close();
}
