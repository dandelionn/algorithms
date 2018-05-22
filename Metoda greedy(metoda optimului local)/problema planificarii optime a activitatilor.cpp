#include <iostream>
#include <fstream>
using namespace std;
ifstream f("greedy1.txt");
struct activitate{int x,y,k;}a[20];
int n,m=1,s[20];
void citeste()
{
    f>>n;
    for(int i=1;i<=n;i++)
        {f>>a[i].x>>a[i].y;
        a[i].k=i;}
}
void sort()
{
    int i,j;
    activitate aux;
    for(i=1;i<=n-1;i++)
       for(j=i+1;j<=n;j++)
           if(a[i].y>a[j].y)
              {
                  aux=a[i];
                  a[i]=a[j];
                  a[j]=aux;
              }
}
void greedy()
{
    int i,j=1;
    s[j]=1;
    for(i=2;i<=n;i++)
        if(a[i].x>=a[s[j]].y)
           s[++j]=i;
    m=j;
}
void afiseaza()
{
    cout<<"Planificarea activitatilor: "<<'\n';
    for(int i=1;i<=m;i++)
       {cout<<"Activitatea "<<a[s[i]].k<<" incepe la ora ";
       cout<<a[s[i]].x<<" si se termina la ora "<<a[s[i]].y<<' '<<'\n';}
}
int main()
{
    citeste();
    sort();
    greedy();
    afiseaza();
    f.close();
}
