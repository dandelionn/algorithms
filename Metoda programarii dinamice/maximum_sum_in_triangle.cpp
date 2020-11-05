#include <iostream>
#include <fstream>
using namespace std;
ifstream f("pd1.txt");
int a[10][10],S[10][10],p[10][10],n;
void citeste()
{
    f>>n;
    int i,j;
    for(i=1;i<=n;i++)
       for(j=1;j<=i;j++)
           f>>a[i][j];
    f.close();
}
void init()
{
    int i;
    for(i=1;i<=n;i++)
       S[n][i]=a[n][i];
}
void p_dinamica()
{
    int i,j;
    for(i=n-1;i>=1;i--)
       for(j=1;j<=i;j++)
          if(S[i+1][j]>S[i+1][j+1])
             {S[i][j]=S[i+1][j]+a[i][j];
             p[i][j]=1;}
          else
             {S[i][j]=S[i+1][j+1]+a[i][j];
             p[i][j]=2;}
}
void afiseaza()
{
    int i,j,q=1,r=1;
    cout<<"suma maxima= "<<S[1][1]<<"= "<<a[1][1]<<"+";
    for(i=1,j=1;i<n;i++)
       {if(p[i][j]==2)
          {
              r=r+1;
              j++;
          }
       q=q+1;
       cout<<a[q][r]<<"+";}
    cout<<'\b'<<' '<<'\n';
}
int main()
{
    citeste();
    init();
    p_dinamica();
    afiseaza();
}
