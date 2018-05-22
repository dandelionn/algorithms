#include <fstream>
using namespace std;

ifstream f("inversmodular.in");
ofstream g("inversmodular.out");

int invm(long long int a,long long int n)
{
    for(long long int x=1;x<n;x++)
        if((x*a)%n==1)
            return x;
}

long long int a,n;

int main()
{
    f>>a>>n;
    g<<invm(a,n);

    f.close(); g.close();

}
