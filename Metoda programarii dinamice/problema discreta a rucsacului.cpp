#include <iostream>
#include <fstream>
using namespace std;
ifstream f("pd4.txt");
struct obiect{int g,c;};
obiect a[20];
int n,G,p[20][20],C[20][20];
void citeste()
{
    int i;
    f>>n>>G;
    for(i=1;i<=n;i++)
       f>>a[i].g>>a[i].c;
    f.close();
}
void p_dinamica()
{
    for(int i=1;i<=n;i++)
       for(int j=1;j<=G;j++)
           if((a[i].g<=j)&&(a[i].c+C[i-1][j-a[i].g]>C[i-1][j]))
              {
                  C[i][j]=a[i].c+C[i-1][j-a[i].g];
                  p[i][j]=i;
              }
           else
              {
                  C[i][j]=C[i-1][j];
                  p[i][j]=p[i-1][j];
              }
}
void afiseaza()
{
    int i=n,j=G,k;
    cout<<"Profit total= "<<C[n][G]<<'\n';
    while(p[i][j]!=0)
         {
             k=p[i][j];
             cout<<"Obiectul "<<k<<" cu greutatea "<<a[k].g;
             cout<<" si profitul "<<a[k].c<<'\n';
             j-=a[p[i][j]].g;
             while(p[i][j]==k)
                  i--;
         }
}
int main()
{
    citeste();
    p_dinamica();
    afiseaza();
}
