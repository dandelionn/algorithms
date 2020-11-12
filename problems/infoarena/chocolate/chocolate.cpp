#include <fstream>
using namespace std;

ifstream f("chocolate.in");
ofstream g("chocolate.out");

/**  I   10000,00001 -> 1
     II  01000       -> 1
     III 00100       -> 0
     IV  1           -> 0

    */

int egal1(int k,int z)
{
    if ( z==1 )
        return 0;
    else
        if ( z%2==1 && k==((z+1)/2)  )
            return 0;
        else
            return 1;
}

int t, n, m, x, y, i;

int main()
{
    f>>t;
    for(i=1;i<=t;i++)
        {f>>n>>m>>x>>y;
        if(n==1)
           g<<egal1(y,m)<<'\n';
        else
           if(m==1)
              g<<egal1(x,n)<<'\n';
           else
              if(egal1(x,n)==1)
                 g<<!egal1(y,m)<<'\n';
              else
                 g<<egal1(y,m)<<'\n';}
    f.close();
    g.close();
}
