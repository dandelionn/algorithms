#include <iostream>
#include <fstream>
using namespace std;
ifstream f("graf8.in");
float medie(int d[],int m)
{
    float s=0;
    int i;
    for(i=1;i<=m;i++)
        s+=d[i];
    return s/m;
}
void verif(int a[][20],int n,int m,int d[],float s)
{
    int i,j,q;
    for(i=1;i<=m;i++)
       if(d[i]>s)
          {for(j=1;j<=n;j++)
             {if(a[j][i]==-1)
                cout<<j<<' ';
             else
                if(a[j][i]==1)
                   q=j;}
          cout<<q<<" cu lungimea arcului "<<d[i]<<'\n';}
}
int main()
{
    int n,m,a[20][20],k,i,j,d[20];
    float s;
    f>>n>>m;
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
           a[i][j]=0;
    for(k=1;k<=m;k++)
       {
           f>>i>>j;
           a[i][k]=-1;a[j][k]=1;
           f>>d[k];
       }
    s=medie(d,m);
    cout<<"lungimea medie= "<<s<<'\n';
    verif(a,n,m,d,s);
    f.close();
}
