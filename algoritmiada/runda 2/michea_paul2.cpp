#include <fstream>

using namespace std;

ofstream g("ski.out");

int n,m,I,V,vI,vV,vT,T,A,B,D,i,poz=-1;;
long a[1001][1001],a1[1001],tmin=100000000;
void init()
{
    int i,j;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
           if(i==j)
              a[i][j]=0;
           else
              a[i][j]=tmin;
}
void transformare()
{
    int k,i,j;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(a[i][k]&&a[k][j]&&(a[i][j]>a[i][k]+a[k][j]||!a[i][j])&&i!=j)
                    a[i][j]=a[i][k]+a[k][j];
}
long max1(long x,long y)
{
    if(x>y)
      return x;
    else
      return y;
}
void citire1()
{
    ifstream f("ski.in");
    f>>n>>m>>I>>V;
    f>>vI>>vV>>vT;
    init();
    for(i=1;i<=m;i++)
       {f>>T>>A>>B>>D;
       if(T==1)
          {a[A][B]=(int)(((float) (D*1000))/(((float)(vT*1000))/3600.0));
          a[B][A]=a[A][B];}
       if(T==2)
          a[A][B]=(int)(((float) (D*1000))/(((float)(vI*1000))/3600.0));}
    f.close();
}
void citire2()
{
    ifstream f("ski.in");
    f>>n>>m>>I>>V;
    f>>vI>>vV>>vT;
    init();
    for(i=1;i<=m;i++)
       {f>>T>>A>>B>>D;
       if(T==1)
          {a[A][B]=(int)(((float) (D*1000))/(((float)(vT*1000))/3600.0));
          a[B][A]=a[A][B];}
       if(T==2)
          a[A][B]=(int)(((float) (D*1000))/(((float)(vV*1000))/3600.0));}
    f.close();
}
int main()
{
    citire1();
    transformare();
    for(i=1;i<=n;i++)
        a1[i]=a[I][i];
    citire2();
    transformare();
    long h;
    for(i=1;i<=n;i++)
        {h=max1(a1[i],a[V][i]);
        if(h<tmin)
            {tmin=h;
            poz=i;}}
    if(poz>0)
       {h=tmin/3600;
       tmin-=h*3600;
       long minut=tmin/60;
       tmin-=minut*60;
       g<<poz<<'\n'<<h<<':'<<minut<<':'<<tmin;}
    else
       g<<poz;
    g.close();
    return 0;
}
