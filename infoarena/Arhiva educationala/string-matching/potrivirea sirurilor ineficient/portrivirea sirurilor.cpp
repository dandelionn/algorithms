#include <fstream>
#include <string.h>
using namespace std;

ifstream f("strmatch.in");
ofstream g("strmatch.out");

char a[2000001],b[2000001],*p;
int nr=0,i,poz[2000001];

int main()
{

    f>>b>>a;

    p=strstr(a,b);
    while(p!='\0')
       {nr++;
       if(nr<=1000)
          poz[nr]=p-a;
       p=strstr(++p,b);}
    g<<nr<<'\n';
    if(nr>1000)
      nr=1000;
    for(i=1;i<=nr;++i)
        g<<poz[i]<<' ';

    f.close();
    g.close();
}
