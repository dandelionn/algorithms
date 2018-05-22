#include <fstream>
using namespace std;
ifstream f("suma.in");
ofstream g("suma.out");
struct elem{int val,poz;};
struct drum{int poz,j,z;};
elem a[100][100][100];
drum d[100][100][100];
void minim(elem x,elem y,elem k,elem w,int i,int j,int z)
{
    if(x.val<=y.val&&x.val<=k.val&&x.val<=w.val)
       {a[i][j][z].val=a[i][j][z].val+x.val;
       d[i][j][z].poz=x.poz;
       d[i][j][z].j=j;
       d[i][j][z].z=z;}
    else
       if(y.val<=x.val&&y.val<=k.val&&y.val<=w.val)
          {a[i][j][z].val=a[i][j][z].val+y.val;
          d[i][j][z].poz=y.poz;
          d[i][j][z].j=j;
          d[i][j][z].z=z+1;}
       else
          if(k.val<=x.val&&k.val<=y.val&&k.val<=w.val)
             {a[i][j][z].val=a[i][j][z].val+k.val;
             d[i][j][z].poz=k.poz;
             d[i][j][z].j=j+1;
             d[i][j][z].z=z;}
          else
              {a[i][j][z].val=a[i][j][z].val+w.val;
              d[i][j][z].poz=w.poz;
              d[i][j][z].j=j+1;
              d[i][j][z].z=z+1;}
}
int main()
{
    int n,i,j,z,m=0,nr=0,z1,j1;
    f>>n;
    for(i=1;i<=n&&m!=n;i++)
        m+=i*i;
    m=i-1;
    g<<m<<' ';
    for(i=1;i<=m;i++)
       for(j=1;j<=i;j++)
          for(z=1;z<=i;z++)
              {nr++;
              f>>a[i][j][z].val;
              a[i][j][z].poz=nr;}
    for(i=m-1;i>=1;i--)
       for(j=1;j<=i;j++)
           for(z=1;z<=i;z++)
              minim(a[i+1][j][z],a[i+1][j][z+1],a[i+1][j+1][z],a[i+1][j+1][z+1],i,j,z);
    g<<a[1][1][1].val<<'\n';
    g<<"1 ";
    j1=1;z1=1;
    for(i=1;i<=m-1;i++)
       {g<<d[i][j1][z1].poz<<' ';
       j1=d[i][j1][z1].j;
       z1=d[i][j1][z1].z;}
    f.close();
}
