#include <fstream>
#include <algorithm>
using namespace std;

ifstream f("arbint.in");
ofstream g("arbint.out");

int v[100001],n,m,a,b,ct,i;

int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>v[i];
    for(i=1;i<=m;i++)
       {f>>ct;
       if(ct==0)
          {f>>a>>b;
          g<<*max_element(&v[a],&v[b+1])<<'\n';}
       if(ct==1)
          {f>>a>>b;
          v[a]=b;}}
     f.close();
     g.close();
     return 0;
}
