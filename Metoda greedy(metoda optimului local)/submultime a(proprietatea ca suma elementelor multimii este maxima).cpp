#include <iostream>
#include <fstream>
using namespace std;
int a[20],c[20],m,n;
ifstream f("elemente2.txt");
void citeste()
{
    int i;
    f>>m;
    for(i=1;i<=m;i++)
        f>>a[i];
    f.close();
}
void sort(int v[],int n)
{
    int i,j,aux;
    for(i=1;i<n;i++)
       for(j=i+1;j<=n;j++)
          if(v[i]<v[j])
             {
                 aux=v[i];
                 v[i]=v[j];
                 v[j]=aux;
             }
}
void greedy()
{
    int i=1;
    if(a[i]>0)
         {while(a[i]>0)
              {c[i]=a[i];
              i++;}
         n=i;}
    else
        {n=2;
        c[i]=a[1];}
}
void afiseaza()
{
    int i;
    for(i=1;i<n;i++)
       cout<<c[i]<<' ';
}
int main()
{
    citeste();
    sort(a,n);
    greedy();
    afiseaza();
}
