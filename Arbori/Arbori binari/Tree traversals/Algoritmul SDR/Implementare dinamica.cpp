#include <iostream>
#include <fstream>
using namespace std;

ifstream f("arbore.txt");
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
void sdr(nod *r)
{
    if(r!=NULL)
       {
           sdr(r->s);
           sdr(r->d);
           cout<<r->nr<<' ';
       }
}
int main()
{
    creare(r);
    sdr(r);
}
