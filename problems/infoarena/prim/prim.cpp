#include <fstream>

using namespace std;
ifstream f("prim.in");
ofstream g("prim.out");

long long int k,n,i,j,nr=0;
bool a[1500000];

int main()
{
    f>>k;

    for(i=2; nr<=k; i++)
        if(!a[i])
            {nr++;
            for(j=i+i;j<=1299743;j+=i)
                a[j]=1;}

    g<<(i-1)*(i-1);
}
