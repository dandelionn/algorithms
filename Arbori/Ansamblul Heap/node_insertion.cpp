#include <iostream>
#include <fstream>

using namespace std;

ifstream f("heap.txt");
const int NMAX=100;
int v[NMAX],n;

void creare_heap()
{
    int i,j,aux;
    f>>n;
    if(n<=NMAX-1)
       {
           f>>v[1];
           for(j=2;j<=n;j++)
               {
                   f>>v[j];i=j;
                   while(i>1)
                        if(v[i]>v[i/2])
                            {aux=v[i];v[i]=v[i/2];v[i/2]=aux;i=i/2;}
                        else
                            i=1;
               }
       }
     else
        cout<<"Arborele nu se poate crea---lungimea fizica a vectorului este depasita"<<'\n';
}
void adauga(int k)
{
    n+=1;
    if(n==NMAX)
       cout<<"Nu se mai poate adauga nodul :|";
    else
        {v[n]=k;
        int aux,i=n;
        while(i>1)
              if(v[i]>v[i/2])
                  {aux=v[i];v[i]=v[i/2];v[i/2]=aux;i=i/2;}
              else
                  i=1;}
}
int main()
{
    int k,i;
    creare_heap();
    for(i=1;i<=n;i++)
        cout<<v[i]<<' ';
    cout<<'\n';
    cout<<"nod adaugat: ";cin>>k;
    adauga(k);
    for(i=1;i<=n;i++)
        cout<<v[i]<<' ';
    f.close();
}
