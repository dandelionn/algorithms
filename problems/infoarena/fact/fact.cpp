#include <fstream>

using namespace std;
ifstream f("fact.in");
ofstream g("fact.out");


long long int p,st,dr,mid,c,nr;

int main()
{
    f>>p;

    st=1;dr=100000000000000;
    while(st<=dr)
    {

        mid=(st+dr)/2;
        nr=0;
        c=5;
        while(c<=mid)
            {nr+=mid/c;
            c*=5;}
        if(nr==p)
           st=dr+1;
        else
           {if(nr<p)
              st=mid+1;
           else
              dr=mid-1;}
    }
    if(p==nr)
        {if(mid<5)
            mid=1;
        if(mid>5&&mid%5!=0)
            mid=mid-mid%5;
        g<<mid;}
    else
        g<<-1;

    f.close();g.close();
}
