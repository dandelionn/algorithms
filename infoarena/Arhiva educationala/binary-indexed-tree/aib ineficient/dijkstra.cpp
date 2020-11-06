#include <fstream>
using namespace std;

ifstream f("dijkstra.in");
ofstream g("dijkstra.out");

#define Nodm 5001
int a[Nodm][Nodm],viz[Nodm]={0},D[Nodm],n,m,i,j,z,x,s;

int main()
{
    s=1;   ///nodul sursa
    f>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
           a[i][j]=Nodm;
    for(x=1;x<=m;x++)
        {f>>i>>j>>z;
        a[i][j]=z;}
    D[1]=0;viz[1]=1;
    for(i=2;i<=n;i++)
        D[i]=a[s][i];

    ///Dijkstra
    for(i=2;i<=n;i++)
       {z=Nodm;
       for(j=2;j<=n;j++)
           if(viz[j]==0&&D[j]<z)
                {z=D[j];
                x=j;}
       viz[x]=1;
       for(j=2;j<=n;j++)
           if(viz[j]==0)
              if(D[x]+a[x][j]<D[j])
                 D[j]=D[x]+a[x][j];}
    for(i=2;i<=n;i++)
        if(D[i]==Nodm)
            g<<0<<' ';
        else
            g<<D[i]<<' ';
    f.close();g.close();

}
