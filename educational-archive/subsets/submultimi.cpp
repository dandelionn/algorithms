#include <fstream>
using namespace std;

ifstream f("submultimi.in");
ofstream g("submultimi.out");

int n,c[16];

void comb(int j)
{
    int i,k;
    if(j<=n)
       for(i=1;i<=n;i++)
          if(i>c[j-1])
              {c[j]=i;
              for(k=1;k<=j;k++)
                 g<<c[k]<<' ';
              g<<'\n';
              comb(j+1);}

}
int main()
{
    f>>n;
    c[0]=0;
    comb(1);
    f.close();g.close();
}
