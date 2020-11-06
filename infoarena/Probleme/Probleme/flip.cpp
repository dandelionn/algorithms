#include <fstream>

using namespace std;

ifstream f("flip.in");
ofstream g("flip.out");

long int a[20][20],sum=0;
int n,m,c[10]={0},sol[10];

void linie(int l)
{
    for(int j=1;j<=m;j++)
        a[l][j]=a[l][j]*(-1);

}
void coloana(int c)
{
    for(int i=1;i<=n;i++)
        a[i][c]=a[i][c]*(-1);
}
void back(int k)
{
    int i;
    if(k<=n+m)
      {for(i=0;i<=m+n;i++)
          if(c[i]==0)
            {sol[k]=i;
            if(i!=0)
               c[i]=1;
            back(k+1);
            c[i]=0;}}
    else
       {int j;
       long int s=0;
        for(i=1;i<=n+m;i++)
           if(sol[i])
               {if(sol[i]>n)
                  coloana(sol[i]-n);
               else
                  linie(sol[i]);}
        for(i=1;i<=n;i++)
           for(j=1;j<=m;j++)
              s+=a[i][j];
        if(s>sum)
           sum=s;}
}
int main()
{
    int i,j;
    f>>n>>m;
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
           f>>a[i][j];
    f.close();
    back(1);
    g<<sum;
    g.close();
}
