#include <iostream>
#include <fstream>
using namespace std;
ifstream f("elem.txt");
struct nod{int info;nod *urm;};
void adauga_nod(nod *&prim,int x)
{
    prim=new nod;
    prim->info=x;
    prim->urm=NULL;
}
void adauga_in_fata(nod *q,int x)
{
    nod *p=new nod;
    p->urm=q->urm;
    p->info=q->info;
    q->info=x;
    q->urm=p;
}
void adauga_ultim(nod *q,int x)
{
    nod *p=new nod;
    p->info=x;
    q->urm=p;
    p->urm=NULL;
}
nod * cauta(nod *prim,int x)
{
    nod *q=prim;
    for(;q->info<x&&q->urm!=NULL;q=q->urm);
    return q;
}
int main()
{
    int x;
    nod *prim,*q;
    f>>x;
    adauga_nod(prim,x);
    f>>x;
    while(x!=0)
         {
             q=cauta(prim,x);
             if(q->info<x)
                 adauga_ultim(q,x);
             else
                 adauga_in_fata(q,x);
             f>>x;
         }
    for(q=prim;q!=NULL;q=q->urm)
       cout<<q->info<<' ';
    f.close();
}
