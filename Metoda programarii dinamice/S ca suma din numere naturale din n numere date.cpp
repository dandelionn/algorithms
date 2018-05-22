#include <iostream>
#include <fstream>
using namespace std;
ifstream f("numere.txt");
int a[100],S,n,m,T[100];
void initread()
{
    int i;
    f>>S>>n;
    for(i=1;i<=n;i++)
       f>>a[i];
    f.close();
    m=0;
    T[0]=-1;
}
void p_dinamica()
{
    int i,j;
    for(i=1;i<=n&&m!=S;i++)
       {
           for(j=m;j>=0;j--)
              if(j+a[i]<=S&&T[j]!=0)
                 {T[j+a[i]]=a[i];
                 cout<<T[j+a[i]]<<'\n';}
           cout<<'\n';
           if(a[i]+m<S)
              m+=a[i];
           else
              m=S;
       }
}
void afisare()
{
    int i;
    for(i=1;i<=S;i++)
        cout<<T[i]<<' ';
    if(T[S]!=0)
       {cout<<"numerele sunt ";
       for(i=S;i!=0;)
           {cout<<T[i]<<' ';
           i-=T[i];}}
}
int main()
{
    initread();
    p_dinamica();
    afisare();
}
