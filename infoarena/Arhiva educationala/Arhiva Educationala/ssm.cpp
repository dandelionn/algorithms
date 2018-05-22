#include <fstream>
using namespace std;
ifstream f("ssm.in");
ofstream g("ssm.out");
int main()
{
    long int i,min,j,in,sf,n,bs=-100000,x,sum=-100000;
    f>>n;
    for(i=1;i<=n;i++)
       {
           f>>x;
           if(sum<0&&x>sum)
               {sum=x;
               j=i;}
           else
               sum+=x;
           if(bs<sum)
              {in=j;
              bs=sum;
              sf=i;}
       }
    g<<bs<<' '<<in<<' '<<sf;
    f.close();g.close();
}
