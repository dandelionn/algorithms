#include <fstream>
#include <iostream>
using namespace std;
struct obiect{int k;float g,c,e;}a[20];
int n,m,s[20];
float x[20],G,Gr;
ifstream f("greedy2.txt");
void citeste()
{
    int i;
    f>>n>>G;
    for(i=1;i<=n;i++)
        {f>>a[i].g>>a[i].c;
        a[i].e=a[i].c/a[i].g;
        a[i].k=i;}
    f.close();
}
void sort()
{
    int i,j;
    obiect aux;
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
             if(a[i].e<a[j].e)
                {
                    aux=a[i];
                    a[i]=a[j];
                    a[j]=aux;
                }
}
void greedy()
{
    int i,j=0;Gr=G;
    for(i=1;i<=n&&Gr!=0;i++)
        if(Gr>=a[i].g)
              {
                  s[++j]=i;
                  x[j]=1;
                  Gr-=a[i].g;
              }
        else
              {
                  s[++j]=i;
                  x[j]=Gr/a[i].g;
                  Gr=0;
              }
    m=j;
}
void afiseaza()
{
    for(int i=1;i<=m;i++)
       {
           cout<<"Obiectul "<<a[s[i]].k<<" in cantitatea ";
           cout<<x[i]*a[s[i]].g<<'\n';
       }
}
int main()
{
    citeste();
    sort();
    greedy();
    afiseaza();
}
