#include <iostream>
#include <fstream>

using namespace std;

ifstream f("heap.in");
int const NMAX=100;
int v[NMAX],n;
void creare_heap()
{
    int i,j,aux;f>>n;
    if(n<=NMAX-1)
       {
           f>>v[1];
           for(j=2;j<=n;j++)
               {f>>v[j];i=j;
               while(i>1)
                  if(v[i]>=v[i/2])
                      {
                          aux=v[i];v[i]=v[i/2];v[i/2]=aux;
                          i=i/2;
                      }
                   else
                      i=1;}
       }
     else
        cout<<"Nu se poate crea-arborele are mai multe noduri decat lungimea fizica a vectorului"<<'\n';
}
int main()
{
    creare_heap();
    for(int i=1;i<=n;i++)
        cout<<v[i]<<' ';
    f.close();
}
