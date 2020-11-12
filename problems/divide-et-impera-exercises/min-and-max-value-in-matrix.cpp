#include <iostream>
using namespace std;
int v[10][10],n,m;
void combina(int x,int y,int &z1,int &z2)
{
    if(v[x][y]<z1)
       z1=v[x][y];
    if(v[x][y]>z2)
       z2=v[x][y];
}
void divizeaza(int s,int d,int &m)
{
    m=(s+d)/2;
}
void dei(int s,int d,int &d2,int &z1,int &z2,int &nr)
{
    int m;
    if(s==d)
       {
           if(nr!=0)
             {
                 combina(s,nr,z1,z2);
             }
           if(nr==0)
             dei(1,d2,d2,z1,z2,s);
       }
    else
       {
           divizeaza(s,d,m);
           dei(s,m,d2,z1,z2,nr);
           dei(m+1,d,d2,z1,z2,nr);
       }
}
int main()
{
    int i,j,nr=0,z1=999999,z2=-999999;
    cout<<"n= ";cin>>n;
    cout<<"m= ";cin>>m;
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
          cin>>v[i][j];
    for(i=1;i<=n;i++)
        {for(j=1;j<=m;j++)
           cout<<v[i][j]<<"  ";
        cout<<'\n';}
    dei(1,m,n,z1,z2,nr);
    cout<<"valoarea minima "<<z1<<'\n';
    cout<<"valoare maxima "<<z2;
}
