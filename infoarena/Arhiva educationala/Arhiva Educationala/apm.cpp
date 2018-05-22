#include <fstream>
using namespace std;
ifstream f("apm.in");
ofstream g("apm.out");
struct muchie{int x,y,c;};
muchie u[400001];
int n,m,L[200001];
void citeste()
{
    int i;
    f>>n>>m;
    for(i=1;i<=m;i++)
        f>>u[i].x>>u[i].y>>u[i].c;
}
void init()
{
    for(int i=1;i<=n;i++)
       L[i]=i;
}
void sortare()
{
    muchie aux;
    int i,j;
    for(i=1;i<=n-1;i++)
       for(j=i+1;j<=n;j++)
           if(u[i].c>u[j].c)
              {
                  aux=u[i];
                  u[i]=u[j];
                  u[j]=aux;
              }
}
int main()
{
    citeste();init();sortare();
    int i=1,k=0,j,ct=0,x,y,a[200001][2];
    while(k<n-1)
         {
             if(L[u[i].x]!=L[u[i].y])
                 {
                     k++;
                     ct=ct+u[i].c;
                     a[k][0]=u[i].x;
                     a[k][1]=u[i].y;
                     x=L[u[i].y];
                     y=L[u[i].x];
                    for(j=1;j<=n;j++)
                        if(L[j]==x)
                            L[j]=y;
                 }
             i++;
         }
    g<<ct<<'\n'<<k<<'\n';
    for(i=1;i<=k;i++)
       g<<a[i][0]<<' '<<a[i][1]<<'\n';
    g.close();
}
