#include <iostream>
#include <fstream>
using namespace std;
ifstream f("dijkstra.in");
ofstream g("dijkstra.out");
#define Nmax 5000
int a[100][100],d[100],s[100],p[100],n;
void init()
{
    f>>n;
    int i,j;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
           if(i!=j)
              a[i][j]=Nmax;
           else
             a[i][j]=0;
}
void citeste()
{
    int i,j,c,m,k;
    f>>m;
    for(k=1;k<=m;k++)
        {f>>i>>j>>c;
         a[i][j]=c;
         a[j][i]=c;}
    f.close();
}
void generare_drum(int x)
{
    int i,j,min,y;
    s[x]=1;
    for(i=1;i<=n;i++)
       {
           d[i]=a[x][i];
           if(i!=x&&d[i]<Nmax)
              p[i]=x;
       }
    for(i=1;i<=n-1;i++)
       {min=Nmax;
       for(j=1;j<=n;j++)
          if(s[j]==0&&d[j]<min)
             {min=d[j];
             y=j;}
       s[y]=1;
       for(j=1;j<=n;j++)
          if((d[y]+a[y][j]<d[j])&&s[j]==0)
             {d[j]=d[y]+a[y][j];
             p[j]=y;}}}
void drum(int i)
{
    if(p[i]!=0)
       drum(p[i]);
    cout<<i<<' ';
}
void afisare(int x)
{
   for(int i=1;i<=n;i++)
      if(i!=x)
         if(p[i]!=0)
            g<<d[i]<<' ';
   g.close();
}
int main()
{
    int x=1;
    init();citeste();generare_drum(x);afisare(x);
}
