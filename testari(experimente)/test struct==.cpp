#include <iostream>
using namespace std;
struct nod{int info;nod *urm;};
int main()
{
    nod *prim,*ultim;
    prim=new nod;ultim=new nod;
    ultim->info=3;ultim->urm=NULL;
    prim->info=3;prim->urm=ultim;
    if(ultim==prim)
       {cout<<"da ";
       cout<<ultim->info<<' '<<prim->info<<'\n';
       cout<<ultim->urm<<' '<<prim->urm;}
}
