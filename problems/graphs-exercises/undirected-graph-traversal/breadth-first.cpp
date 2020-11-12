#include <iostream>
#include <fstream>
using namespace std;
ifstream f("BF.in");
int a[20][20],n,c[20],x,vizitat[20]={0},prim,ultim,k;
void citire()
{
    int i,j;
    f>>n;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          f>>a[i][j];
    f.close();
}
void init(int k)
{
    prim=ultim=1;
    c[prim]=k;
    vizitat[k]=1;
}
void adauga(int i)
{
    ultim++;
    c[ultim]=i;
    vizitat[i]=1;
}
void elimina()
{
    prim++;
}
int este_vida()
{
    return prim>ultim;
}
void prelucrare()
{
    int i;
    while(!este_vida())
         {
             k=c[prim];
             for(i=1;i<=n;i++)
                 if(a[k][i]&&!vizitat[i])
                    adauga(i);
             elimina();
         }
}
void afiseaza()
{
    for(int i=1;i<=n;i++)
       cout<<c[i]<<' ';
}
int main()
{
    cout<<"nodul de la care incepe parcurgerea: ";cin>>k;
    citire();
    init(k);
    prelucrare();
    afiseaza();
}
