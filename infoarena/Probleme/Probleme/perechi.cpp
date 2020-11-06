#include <fstream>
#include <math.h>
using namespace std;
ifstream f("perechi.in");
ofstream g("perechi.out");
int i,j,n,m,nr=1;
int main()
{
    f>>n;
    for(i=1;i<=n/2;i++)
         {if(n%i==0)
            nr++;
         if(i<=sqrt(n))
            if(n%i==0&&n%(n/i)==0)
                nr++;}
    g<<nr;
    f.close();
    g.close();
}
