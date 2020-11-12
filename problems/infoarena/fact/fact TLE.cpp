#include <fstream>

using namespace std;
ifstream f("fact.in");
ofstream g("fact.out");

int n,p,nr,c;

int main()
{
    f>>p;

    nr=0;
    for(n=1;nr!=p||nr>p;n++)
        {c=n;
        while(c%5==0)
            {c/=5;
            nr++;}}
    if(nr==p)
       {if(p==0)
          g<<1;
       else
          g<<n-1;}
    else
        g<<-1;
    f.close();g.close();
}
