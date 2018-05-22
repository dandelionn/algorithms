#include <iostream>
#include <fstream>
using namespace std;
ifstream f("obiecte.txt");
struct obiect{int k;float g,v;}a[20];
float x[20],G,Gr;
int m,n,s[20];
void citeste()
{
    int i;
    f>>n>>G;
    for(i=1;i<=n;i++)
        {f>>a[i].g>>a[i].v;
        a[i].k=i;}
    f.close();
}
void sort()
{
    int i,j;
    obiect aux;
    for(i=1;i<n;i++)
       for(j=i+1;j<=n;j++)
           if(a[i].v<a[j].v)
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
        if(a[i].g<=Gr)
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
        {cout<<"obiectul "<<a[s[i]].k<<" in cantitatea ";
        cout<<x[i]*a[s[i]].g<<'\n';}
}
int main()
{
    citeste();
    sort();
    greedy();
    afiseaza();
}
