#include <fstream>
using namespace std;

ifstream f("hogwarts.in");
ofstream g("hogwarts.out");

int v[3][256],n,s[256],x[256],a[256][256],c[256];

void schimb(int &a,int &b)
{
    int aux=a;
    a=b;
    b=aux;
}
void divizeaza1(int s,int d,int &m)
{
    int i=s,j=d,pi=0,pj=1;
    while(i<j)
       {
           if(v[2][i]<v[2][j])
             {
                 schimb(v[1][i],v[1][j]);
                 schimb(v[2][i],v[2][j]);
                 schimb(pi,pj);
             }
           i=i+pi;
           j=j-pj;
       }
    m=i;
}
void QuickSort1(int s,int d)
{
    int m;
    if(s<d)
      {
          divizeaza1(s,d,m);
          QuickSort1(s,m-1);
          QuickSort1(m+1,d);
      }
}
void divizeaza2(int e,int d,int &m)
{
    int i=e,j=d,pi=0,pj=1;
    while(i<j)
       {
           if(s[i]>s[j])
             {
                 schimb(s[i],s[j]);
                 schimb(x[i],x[j]);
                 schimb(pi,pj);
             }
           i=i+pi;
           j=j-pj;
       }
    m=i;
}
void QuickSort2(int s,int d)
{
    int m;
    if(s<d)
      {
          divizeaza2(s,d,m);
          QuickSort2(s,m-1);
          QuickSort2(m+1,d);
      }
}

int i,o,m,k,imp,nrk,j,nr,verif[256],ok;

int main()
{
    f>>n>>m>>k;
    imp=n-k;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
           a[i][j]=0;
    for(i=1;i<=m;i++)
        {f>>s[i];
        x[i]=i;}
    QuickSort2(1,m);
    for(i=1;i<=n;i++)
        {v[1][i]=i;
        v[2][i]=1;}
    for(i=1;i<=k;i++)
        {f>>o;
        v[2][o]=0;}
    while(f>>i>>o)
         v[2][i]+=o;
    QuickSort1(1,n);
    c[1]=v[1][1];
    nrk=1;
    k=1;
    f.close();
    for(i=1;i<=m;i++)
        {nr=1;
        a[i][v[1][nr]]=v[1][nr];
        v[2][nr]--;
        nr++;
        for(j=1;j<s[i];j++)
           {
               a[i][v[1][nr]]=v[1][nr];
               v[2][nr]--;
               nr++;
           }
        ok=1;
        for(j=1;j<=k&&ok==1;j++)
            {if(a[i][c[j]])
               ok=1;
            else
               ok=0;}
        if(ok==1)
            {for(j=1;j<=n;j++)
                if(a[i][j])
                   c[j]=a[i][j];
            verif[nrk]=i;
            nrk++;
            k=s[i];}
        QuickSort1(1,imp);}

    for(i=1;i<=m;i++)
        {for(j=1;j<=n;j++)
            if(a[x[i]][j])
               g<<a[x[i]][j]<<' ';
        g<<'\n';}
    g<<nrk-1<<'\n';
    for(i=1;i<=nrk-1;i++)
       {for(j=1;j<=n;j++)
           if(a[verif[i]][j])
              g<<a[verif[i]][j]<<' ';
       g<<'\n';}
    return 0;
}
