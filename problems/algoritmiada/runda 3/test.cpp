#include <iostream>
#include <fstream>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

char n[100],a[101],b[101];
int k,c=8,mod=3,nr=0,i;

int main()
{
    f>>n;
    cout<<n[0]-'0';
    cout<<n[1]-'0';
    cout<<n[2]-'0';
    cout<<n[3]-'0';
    cout<<n[4]-'0';
    cout<<n[5]-'0';
    cout<<'\n';
    i=mod+'0';
    cout<<(char) (c/mod+'0')<<'\n';
    cout<<(char) (mod+'0');
    f.close();
    g.close();
    return 0;
}
