#include <fstream>

using namespace std;
ifstream f("perm.in");
ofstream g("perm.out");

long long int n,k,i,p1=1,p2=1;

int main()
{
    f>>n>>k;
    for(i=1;i<=n-k-1;i++)
        {p1*=2;
        p2*=i;}
    p2*=n-k;
    g<<p1*p2;
    f.close();g.close();
}
