#include <fstream>
#include <iomanip>
#include <iostream>
 
using namespace std;
 
int main()
{
    int n;
    double x[100001];
    double y[100001];
 
    ifstream f("aria.in");
    ofstream g("aria.out");
 
    f >> n;
    for(auto i=0; i<n; ++i)
    {
        f >> x[i] >> y[i];
    }
    x[n] = x[0];
    y[n] = y[0];
 
    double s = 0;
 
    for(auto i=0; i<n; ++i)
    {
        s += (x[i] *  y[i+1]  - x[i+1] *  y[i]);
    }
 
    s = s > 0 ? s : -s;
    s = s / 2;
 
    g << std::fixed << std::setprecision(5) << s;
    return 0;
}