#include <fstream>

using namespace std;

ifstream f("capsunele.in");
ofstream g("capsunele.out");

long long int c[1000001],a[1000001],n,m,i,j,ind,x1,x2,nr;

void divizeaza(long long int s,long long int d,long long int &m)
{
    long long int i=s,j=d,pi=0,pj=1,aux;
    while(i<j)
       {
           if(a[i]>a[j])
             {
                 aux=a[i];
                 a[i]=a[j];
                 a[j]=aux;
                 aux=pi;
                 pi=pj;
                 pj=aux;
             }
           i=i+pi;
           j=j-pj;
       }
    m=i;
}
void QuickSort(long long int s,long long int d)
{
    long long int m;
    if(s<d)
      {
          divizeaza(s,d,m);
          QuickSort(s,m-1);
          QuickSort(m+1,d);
      }
}


int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>c[i];
    for(i=1;i<=m;i++)
        {f>>ind>>x1>>x2;
        if(ind==2)
           c[x1]=x2;
        else
           {for(j=x1;j<=x2;j++)
               a[j]=c[j];
           QuickSort(x1,x2);
           a[x2+1]=0;
           if(a[x1]!=a[x1+1])
              g<<a[x1]<<'\n';
           else
               {nr=1;
               for(j=x1+1;j<=x2;j++)
                  if(a[j]==a[j-1])
                     {nr++;
                     if(nr%2==1&&j==x2)
                        g<<a[j]<<'\n';}
                  else
                     {if(nr%2==0)
                        {if(j==x2)
                           g<<a[j]<<'\n';
                        else
                          nr=1;}
                     else
                        {g<<a[j-1]<<'\n';
                        j=x2+1;}}}}}
     f.close();
     g.close();
     return 0;
}
