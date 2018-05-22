#include <fstream>
using namespace std;
ifstream f("ssm.in");
ofstream g("ssm.out");
struct sec{long int i,v,s;};
const int Nmax = 6000001;
sec a[Nmax][Nmax];
int main()
{
    int i,j;
    long int y,n,ms=-1000,v[Nmax];
    f>>n;
    for(i=1;i<=n;i++)
       {f>>a[1][i].v;
       a[1][i].i=i;
       a[1][i].s=a[1][i].v;}
    f.close();
    y=n;
    for(i=2;i<=n;i++)
       {y--;
       for(j=1;j<=y;j++)
           {a[i][j].v=a[i-1][j+1].v;
           a[i][j].i=a[i-1][j+1].i;
           a[i][j].s=a[i-1][j].s+a[i-1][j+1].v;
           if(a[i][j].s>ms)
              {ms=a[i][j].s;
              v[1]=ms;
              v[2]=a[1][j].i;
              v[3]=a[i][j].i;}}}
    for(i=1;i<=3;i++)
       g<<v[i]<<' ';
    g.close();
}

