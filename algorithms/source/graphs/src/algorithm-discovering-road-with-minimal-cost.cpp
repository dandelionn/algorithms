#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cost.in");
int const nrmax=5000;
void init(int a[][20],int n)
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            a[i][j]=nrmax;
}
void transformare(int a[][20],int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
       for(i=1;i<=n;i++)
          for(j=1;j<=n;j++)
              if(i!=j)
                 {if(i!=k&&j!=k)
                    if(a[i][k]+a[k][j]<a[i][j])
                       a[i][j]=a[i][k]+a[k][j];}
              else
                 a[i][j]=0;
}
void drum(int a[][20],int n,int i,int j)
{
    int k,gasit;
    for(k=1,gasit=0;k<=n&&!gasit;k++)
       if(i!=k&&j!=k&&a[i][k]+a[k][j]==a[i][j])
          {
              drum(a,n,i,k);
              drum(a,n,k,j);
              gasit=1;
          }
    if(!gasit)
       cout<<j<<' ';
}
int main()
{
    int a[20][20],n,i,j,c,x,y;
    f>>n;
    init(a,n);
    while(f>>i>>j>>c)
         a[i][j]=c;
    f.close();
    transformare(a,n);
    cout<<"matricea costurilor:"<<'\n';
    for(i=1;i<=n;i++)
        {for(j=1;j<=n;j++)
            cout<<a[i][j]<<' ';
        cout<<'\n';}
    cout<<"nodul x= ";cin>>x;
    cout<<"nodul y= ";cin>>y;
    cout<<"drumul minim dintre nodurile "<<x<<" si "<<y<<" este: "<<x<<" ";
    drum(a,n,x,y);
}
