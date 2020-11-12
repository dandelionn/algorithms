#include <iostream>
#include <fstream>
using namespace std;
ofstream f("graf11.out");
void term_izo(int a[][2],int n,int m)
{
    int b[20],i,j,g,k=0;
    cout<<"noduri terminale: ";
    for(i=1;i<=n;i++)
       {
           g=0;
           for(j=1;j<=m;j++)
              if(a[j][0]==i||a[j][1]==i)
                 g++;
           if(g==1)
              cout<<i<<' ';
           else
              if(g==0)
                 b[++k]=i;
       }
    cout<<'\n'<<"noduri izolate: ";
    for(i=1;i<=k;i++)
        cout<<b[i]<<' ';
}
int main()
{
    int n,m,a[20][2],i,j,k;
    cout<<"nr de noduri= ";cin>>n;
    cout<<"nr de muchii= ";cin>>m;
    f<<n<<' '<<m<<'\n';
    for(k=1;k<=m;k++)
       {
           cout<<"primul nod al muchiei "<<k<<" : ";cin>>i;
           cout<<"al doilea nod al muchiei "<<k<<" : ";cin>>j;
           a[k][0]=i;
           a[k][1]=j;
           f<<i<<' '<<j<<'\n';
       }
    term_izo(a,n,m);
}
