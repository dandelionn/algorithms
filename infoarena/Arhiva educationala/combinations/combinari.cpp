#include <fstream>
using namespace std;

ifstream f("combinari.in");
ofstream g("combinari.out");

int n,k,c[18];

void comb(int j)
{
    int i;
    if(j<=k)
       {for(i=1;i<=n;i++)
          if(i>c[j-1])
              {c[j]=i;
              comb(j+1);}}
    else
      {for(i=1;i<=k;i++)
          g<<c[i]<<' ';
      g<<'\n';}
}
int main()
{
    f>>n>>k;
    c[0]=0;
    comb(1);
    f.close();g.close();
}
