#include <fstream>
 
std::ifstream f("inversmodular.in");
std::ofstream g("inversmodular.out");
 
void extended_euclid(long long a, long long b, long long &d, long long &x, long long &y)
{
    if( b==0 )
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
 
        extended_euclid(b, a%b, d, x, y);
        auto x0 =x;
        auto y0 =y;
 
        y = x0 - ( a / b ) * y0;
        x = y0;
    }
}
 
int main()
{
    long long a = 0, n = 0;
    long long d, x, y;
 
    f>>a>>n;
    extended_euclid(a, n, d, x, y);
 
    while(x < 1)
    {
        x += n;
    }
 
    g<<x;
 
    f.close(); g.close();
}