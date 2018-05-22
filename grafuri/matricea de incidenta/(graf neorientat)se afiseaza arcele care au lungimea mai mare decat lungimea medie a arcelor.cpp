#include <iostream>
#include <fstream>
using namespace std;
ifstream f("graf7.txt");
float medie(int d[],int m)
{
    int i;
    float s=0;
    for(i=1;i<=m;i++)
       s+=d[i];
    return s/m;
}
void verif(int a[][20],int d[],int n,int m,float s)
{
    int i,j;
    for(i=1;i<=m;i++)
       if(d[i]>s)
          {for(j=1;j<=n;j++)
              if(a[j][i])
                 cout<<j<<' ';
          cout<<"cu lungimea "<<d[i]<<'\n';}
}
int main()
{
    int n,m,a[20][20],i,j,k,d[20];
    float s;
    f>>n>>m;
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
          a[i][j]=0;
    for(k=1;k<=m;k++)
        {f>>i>>j>>d[k];
        a[i][k]=1;a[j][k]=1;}
    f.close();
    s=medie(d,m);
    cout<<"lungimea medie= "<<s<<'\n';
    verif(a,d,n,m,s);
}
