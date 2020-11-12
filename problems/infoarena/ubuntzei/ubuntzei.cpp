#include <fstream>
using namespace std;
ifstream f("ubuntzei.in");
ofstream g("ubuntzei.out");
#define INF 5000000
#define NMAX 2001
int n,m,k,a[NMAX][NMAX],c[NMAX],x,y,z,s=50000,v[NMAX],st[NMAX],ev,as;
void init()
{
    st[k]=0;
}
int succesor()
{
    if(st[k]<z)
       {st[k]++;
       return 1;}
    else
       return 0;
}
int valid()
{
    for(int i=1;i<k;i++)
       if(st[i]==st[k])
          return 0;
    return 1;
}
int solutie()
{
    return k==z&&v[st[k]]==y;
}
void tipar()
{
    int s1=0;
    for(int i=1;i<=z-1;i++)
        s1+=a[v[st[i]]][v[st[i+1]]];
    if(s1<s)
       s=s1;
}
void back()
{
    st[1]=x;
    k=2;
    init();
    while(k>1)
        {
            as=1;ev=0;
            while(as && !ev)
                 {
                     as=succesor();
                     if(as)
                        ev=valid();
                 }
            if(as)
               if(solutie())
                  tipar();
               else
                  {k++;
                  init();}
            else
               k--;
        }
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
        back();
    else
        s=a[1][n];
    g<<s;
    g.close();
}
