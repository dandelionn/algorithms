#include <iostream>
#include <fstream>

using namespace std;

ifstream f("arbore.txt");
int t[20],pt[20],n,k,i,vizitat[20]={0},c[20];
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>t[i];
    for(i=1;i<=n;i++)
        f>>pt[i];
    for(i=1;i<=n;i++)
        f>>c[i];
    for(i=1;i<=n;i++)
        c[pt[i]]+=c[t[i]];
    for(i=1;i<=n;i++)
        cout<<"Nodul "<<i<<" are totalul "<<c[i]<<'\n';
}
