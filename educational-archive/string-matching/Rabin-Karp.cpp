#include <fstream>
#include <string.h>
#include <iostream>
using namespace std;

ifstream f("strmatch.in");
ofstream g("strmatch.out");

char a[2000002],b[2000002];
long int ha=0,hb=0,ok,i,j,nr=0,n,m,z,poz[1001];

int main()
{
    f>>a>>b;
    m=strlen(a)-1;n=strlen(b)-1;
    cout<<m<<' '<<n<<'\n';
    for(i=0;i<=m;i++)
       ha=(ha*101 + a[i])%666013;
    cout<<ha;
    if(m<=n)
      {for(i=0;i<m;i++)
         hb=(hb*101 + b[i])%666013;
      cout<<hb;
      for(i=m;i<=n;i++)
         {hb=(hb*101 + b[i])%666013;
         cout<<"hb"<<'\n';
         cout<<hb<<' '<<ha<<'\n';
         if(ha==hb)
            {ok=0;
            for(j=i-m,z=0;j<=i;j++,z++)
                if(a[z]!=b[j])
                   ok=1;
            if(ok==0)
               {nr++;
               if(nr<1000)
                  poz[nr]=i-m;}}
         hb=(hb+666013)/101-b[i-1];}}
    g<<nr<<'\n';
    if(nr>1000)
       nr=1000;
    for(i=1;i<=nr;i++)
       g<<poz[i]<<' ';
    f.close();
    g.close();
    return 0;
}
