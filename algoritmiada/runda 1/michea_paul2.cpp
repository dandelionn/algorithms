#include <fstream>

using namespace std;

ifstream f("templu.in");
ofstream g("templu.out");

int i,j,n,m,c1=1,c2=1,aux1,aux=1,a[10001],t=2;

int main()
{
    f>>n>>m;
    f.close();
    a[1]=1;

    for(i=3;i<=n;i++)
        {
            aux1=a[1]%666013;
            if(t<=m)
               {if(i%2==1)
                  a[t]=2*(a[t-1]%666013);
               else
                  a[t]=a[t-1]%666013+a[t]%666013;}
            for(j=2;j<t;j++)
                {
                    aux=a[j]%666013;
                    a[j]=aux1+aux;
                    aux1=aux;
                }
            a[1]=c1+c2;
            c2=c1;
            c1=a[1]%666013;
            if(t<=m)
               if(i%2==0)
                  t++;
        }
    if(n==m)
       g<<a[1]%666013;
    else
       if(m>n/2+1)
          g<<a[n-m+1]%666013;
       else
          g<<a[m]%666013;
    g.close();
    return 0;
}
