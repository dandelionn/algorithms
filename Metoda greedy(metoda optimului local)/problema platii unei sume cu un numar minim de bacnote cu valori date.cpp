#include <iostream>
#include <fstream>
using namespace std;
ifstream f("bancnote.txt");
int a[20],S,n;
void citeste()
{
    int i;
    f>>n>>S;
    for(i=1;i<=n;i++)
       f>>a[i];
    f.close();
}
void sort()
{
    int i,j,aux;
    for(i=1;i<n;i++)
       for(j=i+1;j<=n;j++)
              if(a[i]<a[j])
                 {
                     aux=a[i];
                     a[i]=a[j];
                     a[j]=aux;
                 }
}
void greedy()
{
    int i=1;
    while(S!=0)
       {if(S/a[i]!=0)
          {
              cout<<S/a[i]<<" bancnote cu valoarea "<<a[i]<<'\n';
              S=S%a[i];
          }
       i++;}
}
int main()
{
    citeste();
    sort();
    greedy();
}
