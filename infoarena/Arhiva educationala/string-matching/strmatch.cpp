#include <fstream>
#include <string.h>
using namespace std;

ifstream f("strmatch.in");
ofstream g("strmatch.out");

char a[2000002],b[2000002];
int m,n,urm[2000002],poz[2000002],nr=0;

void prefix()
{
    int i,k;
    k=0;
    urm[1]=0;
    for(i=2;i<=m;i++)
       {
           while(k>0 && a[k+1]!=a[i])
               k=urm[k];
           if(a[k+1]==a[i])
              k=k+1;
           urm[i]=k;
       }
}

void potrivire()
{
    int i,k;
    k=0;
    for(i=1;i<=n;i++)
       {
           while(k>0 &&a[k+1]!=b[i])
               k=urm[k];
           if(a[k+1]==b[i])
              k=k+1;
           if(k==m)
              {nr++;
              if(nr<=1000)
                 poz[nr]=i-m;
              k=urm[k];}
       }
}

int main()
{
    int i;
    f>>a>>b;
    m=strlen(a);n=strlen(b);
    for(i=m+1;i>=1;--i)
        a[i]=a[i-1];
    for(i=n+1;i>=1;--i)
        b[i]=b[i-1];
    prefix();
    potrivire();
    g<<nr<<'\n';
    if(nr>1000)
       nr=1000;
    for(i=1;i<=nr;i++)
        g<<poz[i]<<' ';
    f.close();
    g.close();
    return 0;
}
