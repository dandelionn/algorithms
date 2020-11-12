#include <iostream>
#include <fstream>
using namespace std;
#define vmax 5000
ifstream f("graf43.txt");
int a[vmax][vmax],Q[vmax],H[vmax],n,r;
void init_mc()
{
    f>>n;
    int i,j;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
           if(i!=j)
              a[i][j]=vmax;
           else
              a[i][j]=0;
}
void citeste()
{
    int x,y,c;
    while(f>>x>>y>>c)
         {a[x][y]=c;
         a[y][x]=c;}
    f.close();
}
void init_Q()
{
    for(int i=1;i<=n;i++)
        if(i!=r)
           Q[i]=r;
}
int muchie()
{
    int i,j,min=vmax;
    for(i=1;i<=n;i++)
        if(Q[i]!=0&&a[Q[i]][i]<min)
            {min=a[Q[i]][i];
            j=i;}
    return j;
}
void actualizeaza_Q(int j)
{
    for(int i=1;i<=n;i++)
       if(Q[i]!=0&&a[i][Q[i]]>a[i][j])
           Q[i]=j;
}
void afisare()
{
    cout<<"APM este format din muchiile: "<<'\n';
    for(int i=1;i<=n;i++)
        if(H[i]!=0)
           cout<<"["<<H[i]<<","<<i<<"] ";
}
int main()
{
    int i,j,k=0,ct=0;
    cout<<"Nodul initial: ";cin>>r;
    init_mc();
    citeste();
    init_Q();
    while(k<n-1)
         {
             j=muchie();
             H[j]=Q[j];
             ct=ct+a[Q[j]][j];
             Q[j]=0;
             actualizeaza_Q(j);
             k++;
         }
    cout<<"cost minim= "<<ct<<'\n';
    afisare();
}
