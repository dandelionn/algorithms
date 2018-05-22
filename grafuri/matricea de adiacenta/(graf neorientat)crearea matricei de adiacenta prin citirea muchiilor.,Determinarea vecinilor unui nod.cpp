#include <iostream>
#include <fstream>
using namespace std;
ifstream f("graf3.txt");
void vecini(int a[][10],int n,int i)
{
    int j;
    for(j=1;j<=n;j++)
       if(a[i][j])
          cout<<j<<' ';
}
int main()
{
    int a[10][10],n,m,i,j,k;
    f>>n>>m;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
           a[i][j]=0;
    for(k=1;k<=m;k++)
       {f>>i>>j;
       a[i][j]=1;a[j][i]=1;}
    cout<<"vecini:"<<'\n';
    for(i=1;i<=n;i++)
       {cout<<"vecinii nodului "<<i<<" sunt: ";
       vecini(a,n,i);
       cout<<'\n';}
    f.close();
}
