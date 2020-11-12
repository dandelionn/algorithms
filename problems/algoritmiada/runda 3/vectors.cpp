#include <iostream>
#include <fstream>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int max(int x,int y)
{
    if(x>y)
       return x;
    return y;
}
void adunare(int a[],int n,int b[],int m)
{
    cout<<1;
    int i,j=0,nrm,c[100];
    if(n<m)
       {for(i=n+1;i<=m;i++)
          a[i]=0;
       nrm=m;}
    else
       {for(i=m+1;i<=n;i++)
          b[i]=0;
       nrm=n;}
    for(i=1;i<=nrm;i++)
       c[i]=0;
    for(i=nrm;i>=1;i--)
        {c[++j]+=a[i]+b[i];
        if(c[j]>9)
           {c[j]=c[j]%10;
           c[j+1]=1;}}
    for(i=1;i<=nrm;i++)
        g<<c[i];
}
int main()
{
    int n,m,i,a[101],b[101];
    f>>n>>m;
    for(i=1;i<=n;i++)
       {f>>a[i];
       cout<<a[i];}
    for(i=1;i<=m;i++)
       {f>>b[i];
       cout<<b[i];}
    cout<<'\n';
    adunare(a,n,b,m);
    f.close();
    g.close();
    return 0;
}
