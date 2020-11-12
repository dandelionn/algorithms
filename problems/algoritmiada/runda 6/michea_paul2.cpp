#include <fstream>

using namespace std;

ifstream f("newyork.in");
ofstream g("newyork.out");

#define Nmax 1001
#define FINIT 1500000
int n,m,p[Nmax],v[5],tp[5][Nmax],traseu[Nmax],h;
long int a[Nmax][Nmax];
long long int d[Nmax],dmin[3][Nmax];
bool verif[Nmax][Nmax][5]={0},viz[Nmax];

void init()
{
    int i,j;
    for(i=1;i<=n;i++)
       {dmin[1][i]=FINIT;
       for(j=1;j<=n;j++)
           if(i!=j)
               a[i][j]=FINIT;
           else
               a[i][j]=0;}
}

void citire()
{
    int i,x,y;
    long int t;
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
    int i, j, k, ok;
    long long int min;
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

void drum(int x,int i)
{
    h=0;
    while(tp[i][x])
         {
             traseu[++h]=x;
             x=tp[i][x];
         }
    traseu[++h]=x;
}
void construieste_solutie()
{
    int i,j;
    long long int ct=0;
    for(i=1;i<=n;i++)
        if(dmin[1][i]>0)
            {drum(i,dmin[2][i]);
            for(j=2;j<=h;j++)
               if(!verif[traseu[j-1]][traseu[j]][dmin[2][i]])   //se verifica daca taxa a fost
                  {ct+=a[traseu[j-1]][traseu[j]];                                   //platita
                  verif[traseu[j-1]][traseu[j]][dmin[2][i]]=1;}}
    g<<ct;
}
int main()
{
    int i,j;
    citire();
    for(i=1;i<=4;i++)
        {dijkstra(v[i]);
        for(j=1;j<=n;j++)
           {

           if(d[j]<dmin[1][j])             //salveaza in vectorul d distantele minime si indicele
              {dmin[1][j]=d[j];          //corespunzator nodului de pornire
              dmin[2][j]=i;}
           tp[i][j]=p[j];         //salveaza vectorii responsabili cu traseele in tabloul tp
           }}
    construieste_solutie();
    g.close();
    return 0;
}
