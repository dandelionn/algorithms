#include <iostream>
#include <fstream>
using namespace std;

ifstream f("xor.in");
ofstream g("xor.out");

int a[100],i,n,s;

int main()
{
    f>>n;
    for(i=1;i<=n;i++)
       f>>a[i];
    s=a[1];
    for(i=2;i<=n;i++)
        {s=s^a[i];
        cout<<s<<' ';}
    cout<<s;
}
