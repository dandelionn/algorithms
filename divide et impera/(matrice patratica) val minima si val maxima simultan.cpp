#include <iostream>
using namespace std;
int v[10][10],n;
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
void dei(int s,int d,int &z1,int &z2,int &nr)
{
    int m,x1,y1,x2,y2,x3,y3;
    if(s==d)
       {
           if(nr!=0)
             {
                 combina(s,nr,z1,z2);
             }
           if(nr==0)
             dei(1,n,z1,z2,s);
       }
    else
       {
           divizeaza(s,d,m);
           dei(s,m,z1,z2,nr);
           dei(m+1,d,z1,z2,nr);
       }
}
int main()
{
    int i,j,nr=0,z1=999999,z2=-999999;
    cout<<"n= ";cin>>n;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          cin>>v[i][j];
    for(i=1;i<=n;i++)
        {for(j=1;j<=n;j++)
           cout<<v[i][j]<<"  ";
        cout<<'\n';}
    dei(1,n,z1,z2,nr);
    cout<<"valoarea minima "<<z1<<'\n';
    cout<<"valoare maxima "<<z2;
}
