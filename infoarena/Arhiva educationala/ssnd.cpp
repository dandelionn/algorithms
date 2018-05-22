#include <fstream>
#include <iostream>
using namespace std;

ifstream f("ssnd.in");
ofstream g("ssnd.out");

struct elem{long int nr,suma;}a[1000000];
long int t,i,j;
long long int n;


int main()
{
    f>>t;
    cout<<t<<' ';

    for(i=1;i<=10000;i++)
        {cout<<"!";
        a[i].nr=0;
        a[i].suma=0;}

    cout<<t<<' ';

    for(i=2;i<=1000000;i++)
           if(!a[i].nr)
               {a[i].nr=1;
               k=1;
               d=1;
               pd=i;
               for(j=i+i;j<=1000000;j+=i)
                   {a[j].nr*=(d+1);
                   a[j].suma=

    for(i=2;i<=1;i++)



    cout<<t;

    for(i=1;i<=t;i++)
        {f>>n;
        g<<a[n/2].nr+2<<' '<<a[n/2].suma+1+n<<'\n';}

    f.close();g.close();
}
