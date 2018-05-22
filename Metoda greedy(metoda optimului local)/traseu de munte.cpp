#include <iostream>
#include <fstream>
using namespace std;
ifstream f("inaltimi.txt");
struct traseu{int x,y;};
traseu c[20];
int a[10][10],n,m,k;
void citeste()
{
    int i,j;
    f>>n>>m;
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
          cin>>a[i][j];
    f.close();
    cout<<"coordonatele de plecare: "<<'\n';
    cout<<"x= ";cin>>c[1].x;
    cout<<"y= ";cin>>c[1].y;
}
void search(int i,int j,traseu c[],int k)
{
    int minim=10000;
    if(a[i][j-1]<minim)
       {minim=a[i][j-1];
       c[k+1].x=i;
       c[k+1].y=j-1;}
    if(a[i+1][j-1]<minim)
       {minim=a[i+1][j-1];
       c[k+1].x=i+1;
       c[k+1].y=j-1;}
    if(a[i+1][j]<minim)
       {minim=a[i+1][j];
       c[k+1].x=i+1;
       c[k+1].y=j;}
    if(a[i+1][j+1]<minim)
       {minim=a[i+1][j+1];
       c[k+1].x=i+1;
       c[k+1].y=j+1;}
    if(a[i][j+1]<minim)
       {minim=a[i][j+1];
       c[k+1].x=i;
       c[k+1].y=j+1;}
}
void greedy()
{
    k=0;
    while(c[k].x!=1)
        {
            k++;
            search(c[k].x,c[k].y,c,k);
        }
}
void afisare()
{
    for(int i=1;i<=n;i++)
       {
           cout<<c[i].x<<' '<<c[i].y<<'\n';
       }
}
int main()
{
    citeste();
    greedy();
    afisare();
}

