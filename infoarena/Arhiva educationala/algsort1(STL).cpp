#include <fstream>
#include <algorithm>
using namespace std;

ifstream f("algsort.in");
ofstream g("algsort.out");

long int a[500011],i,n;

int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>a[i];

    sort(a+1,a+n+1);

    for(i=1;i<=n;i++)
        g<<a[i]<<' ';

    f.close();g.close();

    return 0;
}
