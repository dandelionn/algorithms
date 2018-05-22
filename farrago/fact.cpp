#include <fstream>
#include <math.h>
using namespace std;
ifstream f("fact.in");
ofstream g("fact.out");
unsigned long int P,N,a,b,c,nr,m;
int main()
{
    f>>P;N=P;
    while(nr<=P)
    {
        m=N;
        while(m%2==0)
            {a++;
            m=m/2;}
        m=N;
        while(m%5==0)
             {b++;
             m=m/5;}
        m=N;
        while(m%10==0)
            {c++;
            m=m/10;}
        N++;
        nr=a+c;
    }
    g<<nr;
    f.close();
    g.close();
}
