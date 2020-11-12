#include <math.h>
#include <fstream>
#include <string.h>
using namespace std;
ifstream f("blis.in");
ofstream g("blis.out");
#define Nmax 100001
char a[Nmax];
int max1,maxf,n,k;
int main()
{
    int i,j,nr,t;
    f>>k;
    f>>a;
    t=strlen(a);
    for(i=0;i<t;i++)
         {j=i;
         nr=0;
         max1=0;
         while(nr<k&&j>=0)
               {max1+=(a[j]-'0')*pow(2,nr);
               nr++;
               j--;}
         if(max1>maxf)
            maxf=max1;}
    g<<maxf;
}
