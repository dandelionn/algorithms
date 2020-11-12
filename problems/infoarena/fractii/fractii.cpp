#include <fstream>
using namespace std;
ifstream f("fractii.in");
ofstream g("fractii.out");
long a[10001][10001];
long int n,nr=0;
void init()
{
    int i,j;
    f>>n;
    f.close();
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          a[i][j]=1;
}
int max(int i,int j)
{
    if(i>j)
      return i;
    else
      return j;
}
void ciur()
{
    int i,j,k;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          if(a[i][j])
             for(k=2;k<=n/max(i,j);k++)
                  a[i*k][j*k]=0;
}
void cauta()
{
    int i,j;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
           if(a[i][j])
              nr++;
}
int main()
{
    init();
    ciur();
    cauta();
    g<<nr;
    g.close();
}
