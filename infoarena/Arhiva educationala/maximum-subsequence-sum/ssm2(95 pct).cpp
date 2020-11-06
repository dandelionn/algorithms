#include <fstream>
using namespace std;
ifstream f("ssm.in");
ofstream g("ssm.out");
int main()
{
     long int i,min,j,in,sf,n,bs,x,sum=0,besti;
    f>>n;
    min=0;
    bs=-100000;
    for(i=1;i<=n;i++)
       {
           f>>x;
           sum=sum+x;
           besti=sum-min;
           if(min>sum)
              {
                  min=sum;
                  j=i+1;
              }
           if(bs<besti)
              {
                  bs=besti;
                  in=j;
                  sf=i;
              }
       }
    g<<bs<<' '<<in<<' '<<sf;
    f.close();g.close();
}
