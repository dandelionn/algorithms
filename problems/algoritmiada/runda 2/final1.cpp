#include <fstream>
#include <ctime>
#include <iostream>
using namespace std;

ifstream f("hogwarts.in");
ofstream g("hogwarts.out");

int v[3][256];

void schimb(int &a,int &b)
{
    int aux=a;
    a=b;
    b=aux;
}
void divizeaza(int s,int d,int &m)
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
void QuickSort(int s,int d)
{
    int m;
    if(s<d)
      {
          divizeaza(s,d,m);
          QuickSort(s,m-1);
          QuickSort(m+1,d);
      }
}

int i,j,n,o,m,k,s[256],t=0,imp,cmax=0,nrt,nr,a[256][256];

int main()
{
    clock_t start = clock();
    f>>n>>m>>k;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
           a[i][j]=0;
    imp=n-k;
    for(i=1;i<=m;i++)
        f>>s[i];
    for(i=1;i<=n;i++)
        {v[1][i]=i;
        v[2][i]=1;}
    for(i=1;i<=k;i++)
        {f>>o;
        v[2][o]=0;}
    while(f>>i>>o)
         {t++;
         v[2][i]+=o;}
    QuickSort(1,n);
    for(i=1;i<=2;i++)
       {for(j=1;j<=n;j++)
           cout<<v[i][j]<<' ';
       cout<<'\n';}
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
        QuickSort(1,n-k);
        cout<<'\n';
        for(o=1;o<=2;o++)
           {for(j=1;j<=n;j++)
                cout<<v[i][j]<<' ';
           cout<<'\n';}
        cout<<'\n';
        for(j=1;j<=n;j++)
            if(a[i][j])
               cout<<a[i][j]<<' ';
        cout<<'\n';}
    clock_t ends = clock();
    cout<< "Running Time : " << (double) (ends - start) / CLOCKS_PER_SEC << endl;
    return 0;
}
