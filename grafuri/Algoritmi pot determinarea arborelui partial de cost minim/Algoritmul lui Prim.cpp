#include <iostream>
#include <fstream>
using namespace std;
ifstream f("costapm.txt");
int a[50][50],Q[50],H[50],n,r;
#define Nmax 500000
void init_mc()
{
    int i,j;
    f>>n;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          if(i!=j)
             a[i][j]=Nmax;
          else
             a[i][j]=0;
}
void citire_mc()
{
    int i,j,c;
    while(f>>i>>j>>c)
        {a[i][j]=c;
        a[j][i]=c;}
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
    int i,j,min=Nmax;
    for(i=1;i<=n;i++)
       if(Q[i]!=0&&a[Q[i]][i]<min)
          {
              min=a[Q[i]][i];
              j=i;
          }
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
    cout<<"APM este format din muchiile "<<'\n';
    for(int i=1;i<=n;i++)
       if(H[i]!=0)
          cout<<"["<<H[i]<<","<<i<<"] ";
}
int main()
{
    int i,j,k=0,ct=0;
    init_mc();citire_mc();
    cout<<"Nodul initial: ";cin>>r;
    init_Q();
    while(k<n-1)    //cat timp nu s-au gasit cele m muchii ale APM
         {
             j=muchie();   //alege o muchie sigura
             H[j]=Q[j];
             ct+=a[Q[j]][j];   //adauga la arbore nodul si muchia
             Q[j]=0;         //elimina din coada de prioritati nodul adaugat
             actualizeaza_Q(j);   //actualizeaza coada de prioritati
             k++;
          }
    cout<<"costul total= "<<ct<<endl;
    afisare();
}
