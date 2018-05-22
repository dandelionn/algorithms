#include <iostream>
#include <fstream>
using namespace std;
ifstream f("graf2.txt");
int vecini(int a[][10],int n,int i)
{
    int nr=0,j;
    for(j=1;j<=n;j++)
       if(a[i][j]==1||a[j][i]==1)
         nr++;
    return nr;
}
int nr_a(int a[][10],int n)
{
    int i,j,nr=0;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          if(a[i][j])
             nr++;
    return nr;
}
int main()
{
    int a[10][10],n,vec,i,j;
    f>>n;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
           f>>a[i][j];
    vec=vecini(a,n,1);
    for(i=2;i<=n;i++)
       if(vecini(a,n,i)>vec)
           vec=vecini(a,n,i);
    cout<<"nodurile cu numar maxim de vecini sunt ";
    for(i=1;i<=n;i++)
        if(vecini(a,n,i)==vec)
          cout<<i<<' ';
    cout<<'\n'<<"nr de arce= "<<nr_a(a,n);
    cout<<'\n'<<"arcele sunt: "<<'\n';
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
           if(a[i][j])
              cout<<i<<' '<<j<<'\n';
}
