#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cost.in");
int const val=5000;
void init(int a[][20],int n)
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
           if(i!=j)
              a[i][j]=val;
           else
              a[i][j]=0;
}
void generare_drum(int a[][20],int s[],int d[],int p[],int n,int y)
{
    int j;
    for(j=1;j<=n;j++)
       if(!s[j]&&(d[y]+a[y][j]<d[j]))
              {d[j]=d[y]+a[y][j];
              p[j]=y;}
}
void drum(int a[][20],int s[],int d[],int p[],int n)
{
    int i,y=val,j=0;
    for(i=1;i<=n;i++)
        if(d[i]<y&&s[i]==0)
          {y=d[i];
          j=i;}
    if(j)
       {s[j]=1;
       generare_drum(a,s,d,p,n,j);
       drum(a,s,d,p,n);}
}
void nodurile_drumului(int p[],int n)
{
    if(p[n])
       {nodurile_drumului(p,p[n]);
       cout<<n<<' ';}
    else
       cout<<n<<' ';
}
void afisare(int d[],int p[],int n,int x)
{
    int i,j;
    for(i=1;i<=n;i++)
       if(i!=x)
          {cout<<"lungimea minima de la nodul "<<x<<" la nodul "<<i<<" este "<<d[i]<<'\n';
          cout<<"drumul: ";nodurile_drumului(p,i);
          cout<<'\n';}
}
int main()
{
    int a[20][20],s[20]={0},d[20],p[20],i,j,n,c,x;
    f>>n;
    init(a,n);
    while(f>>i>>j>>c)
         a[i][j]=c;
    cout<<"nodul sursa este: ";cin>>x;
    s[x]=1;
    d[x]=0;
    p[x]=0;
    for(i=1;i<=n;i++)
        if(i!=x)
           {d[i]=a[x][i];
           if(d[i]!=val)
              p[i]=x;
           else
             p[i]=0;}
    for(i=1;i<=n;i++)
       cout<<d[i]<<' ';
    cout<<'\n';
    drum(a,s,d,p,n);
    afisare(d,p,n,x);
}
