#include <iostream>
#include <fstream>

using namespace std;

ifstream f("arbore.txt");
ofstream g("arboreout.txt");

struct nod{int nr;nod *s,*d;}*r;
void creare(nod *&r)
{
    int n;
    f>>n;
    if(n==0)
       r=NULL;
    else
       {
           r=new nod;
           r->nr=n;
           creare(r->s);
           creare(r->d);
       }
}
void salvare(nod *r)
{
    if(r==NULL)
       g<<0<<' ';
    else
       {g<<r->nr<<' ';
       salvare(r->s);
       salvare(r->d);}
}
int main()
{
    creare(r);
    salvare(r);
}
