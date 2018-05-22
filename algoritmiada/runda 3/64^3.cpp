#include <fstream>
using namespace std;
ofstream g("room94.out");
int i,j,k,a=1,b=1;
int main()
{
    for(i=1;i<=64;i++)
       for(j=1;j<=64;j++)
           for(k=1;k<=64;k++)
               {if(a!=0)
                 if(b!=0)
                    a+=1;
                    b+=a;
                    a+=b;}
    g<<a<<' '<<b<<' '<<a+b<<' '<<a-b<<' '<<a*b<<' '<<a/b<<' '<<a%b<<'\n';
}
