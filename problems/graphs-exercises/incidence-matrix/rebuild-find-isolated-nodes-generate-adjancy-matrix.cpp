#include <iostream>
#include <fstream>
using namespace std;
ifstream f("graf12.in");
ofstream g("graf12a.in");
void nod_izo(int a[][2],int n,int m)
{
    int i,j,nr;
    cout<<"nodurile izolate sunt ";
    for(i=1;i<=n;i++)
       {nr=0;
       for(j=1;j<=m;j++)
           if(a[j][0]==i||a[j][1]==i)
              nr++;
       if(nr==0)
          cout<<i<<' ';}
}
int main()
{
    int a[20][2],k,n,i,j,m,c[20][20];
    f>>n>>m;g<<n<<' '<<m<<'\n';
    for(k=1;k<=m;k++)
        f>>a[k][0]>>a[k][1];
    nod_izo(a,n,m);
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
           c[i][j]=0;
    for(k=1;k<=m;k++)
        c[a[k][0]][a[k][1]]=1;
    for(i=1;i<=n;i++)
       {for(j=1;j<=n;j++)
           g<<c[i][j]<<' ';
       g<<'\n';}
    f.close();g.close();
}
