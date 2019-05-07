#include <iostream>
#include <fstream>
using namespace std;

ifstream f("heap.in");
const int NMAX=100;
int v[NMAX],n;

void creare()
{
    int i,j,aux;
    f>>n;
    if(n<=NMAX-1)
       {f>>v[1];
       for(j=2;j<=n;j++)
          {f>>v[j];i=j;
          while(i>1)
               if(v[i]>v[i/2])
                  {aux=v[i];v[i]=v[i/2];v[i/2]=aux;i=i/2;}
               else
                  i=1;
          }}
     else
         cout<<"Arborele nu a fost creat--lungimea fizica a vectorului a fost depasita";
}
int elimina()   ///Pt ansamblul Heap Maxim
{
   int i,j,x,aux;
   x=v[1];
   v[1]=v[n];n--;i=1;
   while(i<=n)
        if(2*i<=n)
            {j=2*i;
            if(j+1<=n&&v[j+1]>=v[j])
               j++;
            if(v[i]<v[j])
                  {aux=v[i];v[i]=v[j];v[j]=aux;i=j;}
            else
                   i=n+1;}
        else
            i=n+1;
   return x;
}
int main()
{
    creare();
    cout<<"cheia cea mai mare este: "<<elimina()<<'\n';
    for(int i=1;i<=n;i++)
       cout<<v[i]<<' ';
}
