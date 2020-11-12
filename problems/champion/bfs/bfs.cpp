#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bfs.in");
ofstream g("bfs.out");
#define Nmax 150
int a[Nmax][Nmax],n,m,nr,T,vizitat[Nmax],c[Nmax],prim,ultim;
void init()
{
    f>>n>>m;
    int i,j;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
            a[i][j]=0;
}
void init1()
{
    for(int i=1;i<=n;i++)
        {vizitat[i]=0;
        c[i]=0;}
    prim=ultim=1;
    c[ultim]=1;
    vizitat[prim]=1;
}
void adauga(int i)
{
    ultim++;
    c[ultim]=i;
    vizitat[i]=1;
}
void citeste()
{
    int k,i,j;
    for(k=1;k<=m;k++)
        {f>>i>>j;
        a[i][j]=1;
        a[j][i]=1;}
    cout<<j<<'\n';
}
void cauta(int i,int y)
{
    int j;
    for(j=prim;j<=y;j++)
        if(a[c[i]][c[j]]==0)
           {cout<<c[j]<<' '<<c[i]<<'\n';
           cout<<nr<<'\n';
           nr++;}
}
void parcurgere()
{
    int k,i,y;
    while(!prim>ultim)
         {
             k=c[prim];
             y=ultim;
             for(i=1;i<=n;i++)
                if(a[k][i]==1&&vizitat[i]==0)
                   {adauga(i);
                   if(prim!=y)
                    cauta(i,y);}
             prim++;
         }
}
int main()
{
    int i=0;
    f>>T;
    while(i<T)
         {nr=0;
         i++;
         init();
         citeste();
         init1();
         parcurgere();
         g<<nr<<'\n';}
    f.close();g.close();
}
