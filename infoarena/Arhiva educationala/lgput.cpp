#include <fstream>

using namespace std;

ifstream f("lgput.in");
ofstream g("lgput.out");
#define mod 1999999973

typedef  long long int  lli;

lli n,p,x,r=1;

int power(lli n,lli p)
{
    lli r=1;
    while(p!=1)
        {if(p%2==1)
          r=(n*r)%mod;
        n=(n*n)%mod;
        p=p/2;}
    return (n*r)%mod;
}

int main()
{
    f>>n>>p;

    g<<power(n,p);

    f.close();g.close();
    return 0;
}
