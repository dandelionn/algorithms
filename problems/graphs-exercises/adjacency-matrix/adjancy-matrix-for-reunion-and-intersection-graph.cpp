#include <fstream>
using namespace std;
ifstream f1("g1.in");
ifstream f2("g2.in");
ofstream U("g3.in");
ofstream I("g4.in");
void reuniune(int a[][10],int b[][10],int n)
{
    int i,j;
    for(i=1;i<=n;i++)
       {for(j=1;j<=n;j++)
          if(a[i][j])
             U<<a[i][j]<<' ';
          else
                U<<b[i][j]<<' ';
       U<<'\n';}
}
void intersectie(int a[][10],int b[][10],int n)
{
    int i,j;
    for(i=1;i<=n;i++)
       {for(j=1;j<=n;j++)
           if(a[i][j]==b[i][j])
              I<<a[i][j]<<' ';
           else
              I<<"0"<<' ';
       I<<'\n';}
}
int main()
{
    int n,a[10][10],b[10][10];
    f1>>n;
    int i,j;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
           f1>>a[i][j];
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
           f2>>b[i][j];
    reuniune(a,b,n);
    intersectie(a,b,n);
}
