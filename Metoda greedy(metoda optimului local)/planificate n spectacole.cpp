#include <fstream>
#include <iostream>
using namespace std;
ifstream f("spectacole.txt");
struct activitate{int x,y,k;}a[20];
int m,n,s[20];
void citeste()
{
    f>>n;
    int i,j;
    for(int i=1;i<=n;i++)
       {f>>a[i].x>>a[i].y;
       a[i].k=i;}
}
void sort()
{
    int i,j;
    activitate aux;
    for(i=1;i<n;i++)
       for(j=i+1;j<=n;j++)
           if(a[i].x+a[i].y>a[j].x+a[j].y)
              {aux=a[i];
              a[i]=a[j];
              a[j]=aux;}
}
void greedy()
{
    int i,j=1;
    s[1]=1;
    for(i=2;i<=n;i++)
        if(a[i].x>=a[s[j]].x+a[s[j]].y)
            s[++j]=i;
    m=j;
}
void afiseaza()
{
    int i;
    cout<<"planificarea spectacolelor: "<<'\n';
    for(i=1;i<=m;i++)
       {cout<<"spectacolul "<<s[i]<<" incepe la ora "<<a[s[i]].x;
       cout<<" si se termina la ora "<<a[s[i]].x+a[s[i]].y<<'\n';}
}
int main()
{
    citeste();
    sort();
    greedy();
    afiseaza();
    f.close();
}
