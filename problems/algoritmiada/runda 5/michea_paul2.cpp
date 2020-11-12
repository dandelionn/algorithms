#include <fstream>
#include <math.h>
#include <string.h>

using namespace std;


ifstream f("numere.in");
ofstream g("numere.out");

char ch_n[7001],ch_a[7001],ch_b[7001],ch_c[7001];
long long int n,a,b,c;

int toint(char x[])
{
    long long int i,nr=0,c=0,numar=0;
    for(i=strlen(x)-1;i>=0;)
        {c=0;
        while(x[i]=='Y')
             {c++;
             i--;}
        while(x[i]=='>')
             {c+=10;
             i--;}
        numar+=c*pow(60,nr);
        while(x[i]=='.')
             {i--;
             nr++;}}
    return numar;
}
void tochar(long long int x)
{
    long long int rest,i=0;
    while(x!=0)
         {rest=x%60;
         if(rest>0)
            {while(rest%10!=0)
                {ch_a[i]='Y';
                i++;
                rest--;}
            while(rest/10!=0)
                {ch_a[i]='>';
                i++;
                rest-=10;}
            x/=60;
            if(x>0)
               {ch_a[i]='.';
               i++;}}
         else
            {ch_a[i]='.';
            i++;
            x/=60;}}
    ch_a[i]='\0';
    strrev(ch_a);
}

int main()
{
    long long int i;
    f>>ch_n;
    n=toint(ch_n);
    for(i=1;i<=n;i++)
        {
            f>>ch_b>>ch_c;
            b=toint(ch_b);
            c=toint(ch_c);
            a=pow((float) c,(1.0/((float) b)));
            tochar(a);
            g<<ch_a<<'\n';
        }
    f.close();
    g.close();
    return 0;
}
