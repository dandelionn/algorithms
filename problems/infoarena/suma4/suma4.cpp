#include <fstream>
using namespace std;

ifstream f("suma.in");
ofstream g("suma.out");

long long int a[63366],drum[63366],n,i,nr,nrp,j,k,m,poz,signal;

int nrnivele(int n)
{
    int i=0,nr=1;
    while(i!=n)
        {i+=nr*nr;
        nr++;}
    return nr-1;
}
int el_min(int b,int c,int d,int e)
{
    int i,j;
    if(a[b]<=a[c])
        i=b;
    else
        i=c;
    if(a[d]<=a[e])
        j=d;
    else
        j=e;
    if(a[i]<=a[j])
        return i;
    else
        return j;
}

int main()
{
    f>>n;
    nr=nrnivele(n);
    g<<nr<<' ';k=nr;
    for(i=1;i<=n;i++)
        f>>a[i];

    poz=n-nr*nr;
    nrp=1;
    signal=n-nr*nr-(nr-1)*(nr-1);

    for(i=n;i>=4;)
        {m=el_min(i-nr-1,i-nr,i-1,i);
        a[poz]=a[poz]+a[m];
        drum[poz]=m;
        poz--;
        if(poz==signal)
            {n=n-nr*nr;
            i=n;nr--;
            nrp=1;
            signal=n-nr*nr-(nr-1)*(nr-1);}
        else
            if(poz==n-nr*nr-(nr-1)*nrp)
               {i=n-nrp*nr;
               nrp++;}
            else
               i--;}
    g<<a[1]<<'\n'<<"1 ";j=1;
    for(i=1;i<k;i++)
        {g<<drum[j]<<' ';
        j=drum[j];}
    f.close(); g.close();
}
