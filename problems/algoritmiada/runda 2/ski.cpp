#include <fstream>

using namespace std;

ifstream f("ski.in");
ofstream g("ski.out");

int a[1001][1001],b[1001][1001],n,m,I,V,vI,vV,vT,T,A,B,D,tmin=100000;
void init()
{
    int i,j;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
           if(i==j)
              {a[i][j]=0;
              b[i][j]=0;}
           else
              {a[i][j]=tmin;
              b[i][j]=tmin;}
}
void transformare1()
{
    int k,i,j;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(a[i][k]&&a[k][j]&&(a[i][j]>a[i][k]+a[k][j]||!a[i][j])&&i!=j)
                    a[i][j]=a[i][k]+a[k][j];
}
void transformare2()
{
    int k,i,j;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(b[i][k]&&b[k][j]&&(b[i][j]>b[i][k]+b[k][j]||!b[i][j])&&i!=j)
                    b[i][j]=b[i][k]+b[k][j];
}
int max1(int x,int y)
{
    if(x>y)
      return x;
    else
      return y;
}
int main()
{
    int i,poz=-1;
    f>>n>>m>>I>>V;
    f>>vI>>vV>>vT;
    init();
    for(i=1;i<=m;i++)
       {f>>T>>A>>B>>D;
       if(T==1)
          {a[A][B]=(int)(((float) (D*1000))/(((float)(vT*1000))/3600.0));
          a[B][A]=a[A][B];
          b[A][B]=a[A][B];
          b[B][A]=b[A][B];}
       if(T==2)
          {a[A][B]=(int)(((float) (D*1000))/(((float)(vI*1000))/3600.0));
          b[A][B]=(int)(((float) (D*1000))/(((float)(vV*1000))/3600.0));}}
    f.close();
    int j;
    for(i=1;i<=n;i++)
       {for(j=1;j<=n;j++)
           g<<a[i][j]<<' ';
       g<<'\n';}
    g<<'\n';
    for(i=1;i<=n;i++)
       {for(j=1;j<=n;j++)
           g<<b[i][j]<<' ';
       g<<'\n';}
    g<<'\n';
    transformare1();
    transformare2();
    for(i=1;i<=n;i++)
       {for(j=1;j<=n;j++)
           g<<a[i][j]<<' ';
       g<<'\n';}
    g<<'\n';
    for(i=1;i<=n;i++)
       {for(j=1;j<=n;j++)
           g<<b[i][j]<<' ';
       g<<'\n';}
    g<<'\n';
    int h;
    for(i=1;i<=n;i++)
        if(i!=I&&i!=V)
           {h=max1(a[I][i],b[V][i]);
           if(h<tmin)
              {tmin=h;
              poz=i;}}
    if(poz>0)
       {h=tmin/3600;
       tmin-=h*3600;
       int minut=tmin/60;
       tmin-=minut*60;
       g<<poz<<'\n'<<h<<':'<<minut<<':'<<tmin;}
    else
       g<<poz;
    g.close();
    return 0;
}

