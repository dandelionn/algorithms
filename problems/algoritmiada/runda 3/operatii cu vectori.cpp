#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

char n[100],a[101],b[101];
int k,c=0,mod=3,nr=0,i;

int main()
{
    f>>n;f>>k;
    for(i=0;i<strlen(n);i++)
       if(c<mod)
          {c=c*10+(n[i]-'0');
          cout<<c<<" 1"<<'\n';}
       else
          {a[nr++]=(char) (c/mod+'0');
          cout<<a[nr-1]<<c/mod<<'\n';
          c=c-mod*(c/mod);}
    a[nr]='\0';
    g<<n<<' '<<a;
    f.close();
    g.close();
    return 0;
}
