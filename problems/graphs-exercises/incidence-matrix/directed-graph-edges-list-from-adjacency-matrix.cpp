#include <iostream>
#include <fstream>
using namespace std;
ifstream f("graf2.in");
void vecini(int b[20][2],int m,int v[20],int p)
{
    int i;
    for(i=1;i<=m;i++)
       if(b[i][0]==p)
         v[b[i][1]]=1;
       else
          if(b[i][1]==p)
             v[b[i][0]]=1;
}
int main()
{
    int n,p,a[20][20],i,j,m=0,b[20][2],v[20];
    f>>n>>m;
    for(i=1;i<=n;i++)
       v[i]=0;
    m=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
           f>>a[i][j];
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          if(a[i][j])
             {b[++m][0]=i;
             b[m][1]=j;}
    for(i=1;i<=m;i++)
        cout<<b[i][0]<<' '<<b[i][1]<<'\n';
    cout<<'\n'<<"nodul ";cin>>p;
    vecini(b,m,v,p);
    cout<<"vecinii nodului sunt: ";
    for(i=1;i<=n;i++)
        if(v[i])
           cout<<i<<' ';
    f.close();
}
