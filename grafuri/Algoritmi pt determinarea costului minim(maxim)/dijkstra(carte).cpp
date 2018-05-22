#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cost.txt");
int const MAX=5000;
int a[20][20],s[20],d[20],p[20],n;
void init()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
           if(i!=j)
              a[i][j]=MAX;
           else
              a[i][j]=0;
}
void generare_drum(int x)
{
    int i,j,min,y;
    s[x]=1;
    for(i=1;i<=n;i++)
       {
           d[i]=a[x][i];
           if(i!=x&&d[i]<MAX)
              p[i]=x;
       }
    for(i=1;i<=n-1;i++)
        {for(j=1,min=MAX;j<=n;j++)
            if(s[j]==0&&d[j]<min)
               {
                   min=d[j];
                   y=j;
               }
        s[y]=1;
        for(j=1;j<=n;j++)
           if(s[j]==0&&(d[j]>d[y]+a[y][j]))
              {d[j]=d[y]+a[y][j];
              p[j]=y;}}
}
void drum(int i)
{
    if(p[i]!=0)
      drum(p[i]);
    cout<<i<<' ';
}
void afisare(int x)
{
    int i;
    for(i=1;i<=n;i++)
       if(i!=x)
         {if(p[i]!=0)
            {cout<<"drumul cu costul minim de la nodul "<<x<<" la nodul "<<i<<" are costul "<<d[i]<<'\n';
            drum(i);
            cout<<'\n';}
         else
             cout<<"Nu exista drum de la "<<x<<" la "<<i<<'\n';}
    for(i=1;i<=n;i++)
       cout<<d[i]<<' ';
}
int main()
{
    int x,i,j,c;
    f>>n;
    init();
    while(f>>i>>j>>c)
         a[i][j]=c;
    cout<<"nodul sursa este: ";cin>>x;
    generare_drum(x);
    afisare(x);
}
