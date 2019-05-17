#include <iostream>
#include <fstream>

using namespace std;
ifstream f("arbore.txt");

int t[100],n,i,j,r,c[100],viz[100],prim=0,ultim=1;
int rad()
{
    for(i=1;i<=n;i++)
       if(t[i]==0)
          return i;
    return 0;
}
int main()
{
    f>>n;
    r=rad();
    for(i=1;i<=n;i++)
        f>>t[i];

    c[ultim]=r;
    cout<<c[1]<<' ';
    while(prim<ultim)
         {prim++;
         for(i=1;i<=n;i++)
             if(t[i]==c[prim])
                {c[++ultim]=i;
                cout<<c[ultim]<<' ';}}
}

