#include <fstream>

using namespace std;

ifstream f("room94.in");
ofstream g("room94.out");

int a[10][10];
void back(int l,int c)
{
    int m,n,i,j;
    a[l][c]='1';
    if(l==m||c==n||l==1||c==1)
        a[i][j]='0';
    else
       {if(a[l-1])
          a[i][i]='0';}
}
int main()
{
    int i,j;
    for(i=0;i<=1;i++)
        for(j=0;j<=11;j++)
            {a[i][j]=9;
            a[i+10][j]=9;}
    for(i=0;i<=1;i++)
        for(j=0;j<=11;j++)
            {a[j][i]=9;
            a[j][i+10]=9;}
    for(i=2;i<=9;i++)
        for(j=2;j<=9;j++)
             f>>a[i][j];
    for(i=0;i<=11;i++)
       {for(j=0;j<=11;j++)
          g<<a[i][j]<<' ';
       g<<'\n';}
}
