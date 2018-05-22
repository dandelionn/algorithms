#include <iostream>
#include <string.h>
using namespace std;
int palindrom(char p[] )
{
    char *q; q = strrev(p);
    if ( strcmp(p,q) == 0 )
        return 1;
    return 0;
}
int main()
{
    char p[100];
    cin>>p;
    cout<<p<<'\n';
    cout<<strrev(p)<<'\n';
    cout<<p<<'\n';
}
