#include <iostream>
#include <fstream>
using namespace std;

ifstream f("arbore.txt");
struct nod{int nr;nod *s,*d;}*r1;
void creare(nod *&r)
{
    int n;
    r=new nod;
    f>>n;
    if(n==0)
       r=NULL;
    else
       {
           r->nr=n;
           creare(r->s);
           creare(r->d);
       }
}
void rsd(nod *r)
{
    if(r!=NULL)
       {cout<<r->nr<<' ';
       rsd(r->s);
       rsd(r->d);}
}
int main()
{
    creare(r1);
    rsd(r1);
}
