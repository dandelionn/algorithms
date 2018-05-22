#include <fstream>
#include <math.h>
using namespace std;

ifstream f("lgput.in");
ofstream g("lgput.out");
#define mod 1999999973

long long int n,p,i,c1,c2;

int main()
{
    f>>n>>p;
    c1=n%mod;
    c2=1;
    while(p>1)
     {
         if(p%2==1)
           c2=c2*n%mod;
         c1=c1*c1%mod;
         p/=2;
     }
    g<<c2*c1%mod;
    f.close();g.close();
}
