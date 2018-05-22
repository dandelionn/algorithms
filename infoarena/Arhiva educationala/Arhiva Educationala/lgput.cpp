#include <fstream>
using namespace std;
ifstream f("lgput.in");
ofstream g("lgput.out");
long int n,p;
long int dei(long int p,long int u)
{
    int m;
    if(p==u)
       return n;
    else
        {
          m=(p+u)/2;
          return dei(p,m)*dei(m+1,u);
        }
}
int main()
{
    f>>n>>p;
    g<<dei(1,p)%1999999973;
    f.close();
    g.close();
}
