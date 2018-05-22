#include <fstream>

using namespace std;

ifstream f("fractii.in");
ofstream g("fractii.out");

struct elem{bool v;long long int p1=1,p2=1;} a[1000001];
int i,j,n;
long long int nr;

int main()
{
    f>>n;
    for( i=2; i<=n/2; i++ )
        if( !a[i].v )
            for( j=i+i; j<=n; j+=i )
                 {a[j].v=1;
                 a[j].p1*=i-1;
                 a[j].p2*=i;}

    nr=1;
    for( i=2; i<=n; i++)
        if( !a[i].v )
              nr+=(i-1)*2;
        else
              nr+=(i * a[i].p1) / a[i].p2 * 2;
    g<<nr;
    f.close();g.close();
}
