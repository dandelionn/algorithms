#include <iostream>
#include <fstream>

using namespace std;
ifstream f("arbore1.txt");

int t[100],n,i,j,r,c[100],viz[100],prim=0,ultim=1,numere[20];
int rad()
{
    for(i=1;i<=n;i++)
       if(t[i]==0)
          return i;
    return 0;
}
int main()
{
    int suma=0;
    f>>n;
    r=rad();
    for(i=1;i<=n;i++)
        f>>t[i];
    for(i=1;i<=n;i++)
       f>>numere[i];

    c[ultim]=r;
    while(prim<ultim)
         {prim++;
         for(i=1;i<=n;i++)
             if(t[i]==c[prim])
                {c[++ultim]=i;
                if(numere[i]%2==0)
                   suma+=numere[i];}}
    cout<<"suma= "<<suma;
}

